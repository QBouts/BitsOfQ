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

#include <iomanip>
#include <iostream>
#include <sstream>

// Requirements:
// Initialize JSONWriter with a stream
// serialize name-value pairs using the streaming operator with builtin types
// serialize name-value pairs using the streaming operator with strings
// serialize name-value pairs using the streaming operator with custom classes/structs
// serialization can handle multiple name-value pairs
// serialize list-like type (e.g std::vector) to json array
// allow specifying members of a struct/class
// compile time error should be given when a type can't be serialized

struct Address {
	std::string street_name;
	int house_number;
};

template <typename T>
struct NVP {
	std::string name;
	T value;
};

template <typename T>
NVP(std::string, T) -> NVP<T>;

class JSONWriter {
public:
	explicit JSONWriter(std::ostream& stream) : m_stream(stream) {}

	template <typename T>
	JSONWriter& operator<<(const NVP<T>& nvp) {
		if constexpr (std::is_convertible_v<T, std::string>) {
			m_stream << std::boolalpha << "{ \"" << nvp.name << "\" : \"" << nvp.value << "\" }";
		} else {
			m_stream << std::boolalpha << "{ \"" << nvp.name << "\" : " << nvp.value << " }";
		}
		return *this;
	}

private:
	std::ostream& m_stream;
};

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

TEST(JSONWriterTests, NVPWithBuiltinTypeIsCorrectlySerialized) {
	std::stringstream ss;
	JSONWriter writer{ss};
	writer << NVP{"hello", 42};
	EXPECT_EQ(ss.str(), R"({ "hello" : 42 })");
	ss.str("");

	writer << NVP{"hello", true};
	EXPECT_EQ(ss.str(), R"({ "hello" : true })");
	ss.str("");

	writer << NVP{"hello", 42.5};
	EXPECT_EQ(ss.str(), R"({ "hello" : 42.5 })");
}

TEST(JSONWriterTests, NVPWithStringIsCorrectlySerialized) {
	std::stringstream ss;
	JSONWriter writer{ss};
	writer << NVP{"hello", std::string{"goodbye"}};
	EXPECT_EQ(ss.str(), R"({ "hello" : "goodbye" })");

	ss.str("");
	writer << NVP{"hello", "goodbye"};
	EXPECT_EQ(ss.str(), R"({ "hello" : "goodbye" })");
}