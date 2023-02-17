/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2023 Quirijn Bouts
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#include <gtest/gtest.h>

#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <type_traits>

// This project was completed in a live test driven development demonstration as part of the LetsCode series on the
// BitsOfQ YouTube channel.

// Requirements:
// Initialize JSONWriter with a stream
// serialize name-value pairs using the streaming operator with builtin types
// serialize name-value pairs using the streaming operator with strings
// serialize name-value pairs using the streaming operator with custom classes/structs
// serialization can handle multiple name-value pairs
// serialize list-like type (e.g std::vector) to json array
// allow specifying members of a struct/class
// compile time error should be given when a type can't be serialized

/// Used for testing custom type serialization
struct Address {
	std::string street_name;
	int house_number;
};

/// Used for testing custom type serialization
struct Person {
	std::string name;
	Address address;
};

/// Specifies a name-value pair. Used when streaming to a JSONWriter instance.
template <typename T>
struct NVP {
	const std::string& name;
	const T& value;
};

/// Convenience function to create name-value pairs
template <typename T>
NVP<T> nvp(const std::string& name, const T& value) {
	return NVP<T>{name, value};
}

/// Deduction guide te ensure the NVP struct can be initialized using the uniform initializer syntax without having to
/// specify template parameters.
template <typename T>
NVP(std::string, T) -> NVP<T>;

/// Concept which specifies the category of types that should be serialized to a JSON list / array.
/// We define a list to be a type that support indexing and a .begin() and .end() operator. Furthermore, since string
/// types often also fit this description, we explicitly exclude any string-like types from the concept.
template <typename T>
concept JSONListLike = requires(T t) {
	t[0];
	t.begin();
	t.end();
	requires !std::is_convertible_v<T, std::string>;
};

/// The JSONWriter class can be used to serialize data to json and output it to a stream.
/// Data should be passed to instances of the class using the streaming operator and while wrapped in an NVP (name-value
/// pair) struct.
/// The data is flushed to the stream when the writer instance goes out of scope, following the RAII principle.
class JSONWriter {
	// type trait used to check if a type is an nvp. Used for improved error reporting.
	template <typename T>
	struct is_nvp : std::false_type {};

	template <typename T>
	struct is_nvp<NVP<T>> : std::true_type {};

	template <typename T>
	static constexpr bool is_nvp_v = is_nvp<T>::value;

public:
	explicit JSONWriter(std::ostream& stream) : m_stream(stream) { m_stream << "{ "; }
	~JSONWriter() { m_stream << " }"; }

	template <typename T>
	JSONWriter& operator<<(const T&) {
		static_assert(is_nvp_v<T>, "To serialize to JSON, pass name-value pairs using the NVP struct");
		return *this;
	}


	template <typename T>
	JSONWriter& operator<<(const NVP<T>& nvp) {
		if (!m_first_nvp) {
			m_stream << ", ";
		}
		m_stream << std::boolalpha << "\"" << nvp.name << "\" : ";
		serialize_value(nvp.value);
		m_first_nvp = false;
		return *this;
	}

private:
	std::ostream& m_stream;
	bool m_first_nvp = true;

	template <typename T>
	void serialize_value(const T& t) {
		m_stream << t;
	}

	template <typename T>
		requires(std::is_convertible_v<T, std::string>)
	void serialize_value(const T& t) { m_stream << std::quoted(t); }

	template <JSONListLike L>
	void serialize_value(const L& list) {
		bool is_first = true;
		m_stream << "[ ";
		for (const auto& e : list) {
			if (!is_first) {
				m_stream << ", ";
			}
			serialize_value(e);
			is_first = false;
		}
		m_stream << " ]";
	}

	template <typename T>
		requires(std::is_class_v<T> && !std::is_convertible_v<T, std::string> && !JSONListLike<T>)
	void serialize_value(const T& t) {
		static_assert(
		    requires { serialize(*this, t); },
		    "Serialization of custom classes requires a serialize overload to be defined");
		m_first_nvp = true;
		m_stream << "{ ";
		serialize(*this, t);
		m_stream << " }";
	}
};


/// Serialization definition for custom classes used in the tests ///

void serialize(JSONWriter& writer, const Address& a) {
	writer << NVP{"street_name", a.street_name};
	writer << NVP{"house_number", a.house_number};
}

void serialize(JSONWriter& writer, const Person& p) {
	writer << NVP{"name", p.name};
	writer << NVP{"address", p.address};
}

/////////////////////////////// Tests ///////////////////////////////

TEST(JSONWriterTests, JSONWriterCanBeInitializedWithAStream) {
	JSONWriter writer{std::cout};
}

TEST(JSONWriterTests, CanCreateNVPWithBuiltinTypes) {
	[[maybe_unused]] NVP nvp{"hello", 12};
}

TEST(JSONWriterTests, CanStreamNVPsToJSONWriter) {
	JSONWriter writer{std::cout};
	writer << NVP{"hello", 42};
}
TEST(JSONWriterTests, CanStreamNVPsCreatedWithNVPFunctionToJSONWriter) {
	JSONWriter writer{std::cout};
	writer << nvp("hello", 42);
}


TEST(JSONWriterTests, NVPWithIntIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", 42};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : 42 })");
}

TEST(JSONWriterTests, NVPWithBoolIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", true};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : true })");
}

TEST(JSONWriterTests, NVPWithDoubleIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", 42.5};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : 42.5 })");
}

TEST(JSONWriterTests, MultipleNVPsAreSerializedCorrectly) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", 42};
		writer << NVP{"goodbye", true};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : 42, "goodbye" : true })");

	ss.str("");
}


TEST(JSONWriterTests, NVPWithStringIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", std::string{"goodbye"}};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : "goodbye" })");
	ss.str("");

	{
		JSONWriter writer{ss};
		writer << NVP{"hello", "goodbye"};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : "goodbye" })");
}

TEST(JSONWriterTests, NVPWithStructIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", Address{"some_street", 42}};
	}
	EXPECT_EQ(ss.str(), R"({ "hello" : { "street_name" : "some_street", "house_number" : 42 } })");
}

TEST(JSONWriterTests, NVPWithNestedStructIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"hello", Person{"Bob", Address{"some_street", 42}}};
	}
	EXPECT_EQ(ss.str(),
	          R"({ "hello" : { "name" : "Bob", "address" : { "street_name" : "some_street", "house_number" : 42 } } })");
}


TEST(JSONWriterTests, NVPWithVectorIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"list", std::vector<int>{1, 2, 3, 4}};
	}
	EXPECT_EQ(ss.str(), R"({ "list" : [ 1, 2, 3, 4 ] })");
}

TEST(JSONWriterTests, NVPWithVectorOfStructsIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"list", std::vector<Address>{Address{"some_street", 42}, Address{"some_other_street", 12}}};
	}
	EXPECT_EQ(
	    ss.str(),
	    R"({ "list" : [ { "street_name" : "some_street", "house_number" : 42 }, { "street_name" : "some_other_street", "house_number" : 12 } ] })");
}

TEST(JSONWriterTests, NVPWithSTDArrayIsCorrectlySerialized) {
	std::stringstream ss;
	{
		JSONWriter writer{ss};
		writer << NVP{"list", std::array<int, 4>{1, 2, 3, 4}};
	}
	EXPECT_EQ(ss.str(), R"({ "list" : [ 1, 2, 3, 4 ] })");
}

struct bla {
	int a;
	bool b;
};

// Uncomment these tests to verify that the appropriate compile-time errors are given when non-serializable types are
// passed to the writer.

/*TEST(JSONWriterTests, CompileTimeErrorIsGivenWhenSerializingStructWithoutSerializeFunctionDefined) {
  JSONWriter writer{std::cout};
  writer << NVP{"bla", bla{}};
}*/

/*TEST(JSONWriterTests, CompileTimeErrorIsGivenWhenSerializingNonNVP) {
  JSONWriter writer{std::cout};
  writer << 5;
}*/
