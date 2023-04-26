#pragma once
#include <iostream>
#include <cstring>

namespace CU{

class string{
	friend std::ostream& operator<< (std::ostream& out , const CU::string& s);
	friend string operator+(const string& left, const string& right);
	friend string& operator+=(string& left, const string& right);
	public : 
	 string(const char* data, size_t size = 15 ){
		m_size = size;

		// This needs to be there to support cstrings greater than length of 15
		if (int s = std::strlen(data); s > 15) {
			m_size = s;
		}

		m_data = new char [m_size];
		std::strcpy(m_data,data );
	}

	//Copy constructor
	string(const string& source){
		m_size = source.m_size;
		m_data = new char [m_size]; // We want to do deep copy here.
		std::strcpy(m_data,source.m_data);
	}

	//Copy assignment operator
	string& operator= (const string& right_operand){
		std::cout << "Copy assignment operator called" << std::endl;
		if(this != & right_operand){
			delete[] m_data;
			m_data = new char [right_operand.m_size];
			std::strcpy(m_data,right_operand.m_data);
		}
		return *this;
	}
	
	const char* c_str() const{
		return m_data;
	}

   // return the size of string
	int size() const {
		return std::strlen(m_data);
	}

	// return the capacity of the string()
	int capacity() const {
		return m_size;
	}

	// clear() function
	void clear() {
		// set all of it to 0s (m_data[0] = 0 would have worked as well but this is thorough clear)
		memset(m_data, 0, strlen(m_data)); 
		m_size = 0;
	}

	// insert() function (only implementing inserting a full string before position pos)
	string& insert(int pos, const string& str2) {
		if (pos >= m_size || pos < 0) {
			return *this;
		}

		char* m_new_data = new char[m_size + str2.m_size + 1];

		// if inserting at 0th position
		if (pos == 0) {
			std::strncpy(m_new_data, str2.m_data, str2.m_size);
			std::strcat(m_new_data, m_data);
		}
		
		else {
			std::strncpy(m_new_data, m_data, pos);
			std::strcat(m_new_data, str2.m_data);
			std::strcat(m_new_data, m_data + pos);
		}

		delete [] m_data;
		m_size = m_size + str2.m_size + 1;
		m_data = m_new_data;

		return *this;
	}

	// erase() function : non iterator version and no default length
	string& erase (size_t pos, size_t len) {

		if (pos >= m_size || pos < 0 || (len + pos) > m_size) {
			return *this;
		}

		char* m_new_data = new char[m_size];
		
		// if deleting from 0th position
		if (pos == 0) {
			std::strcpy(m_new_data, m_data + len);
		}

		else {
			std::strncpy(m_new_data, m_data, pos);
			std::strcat(m_new_data, m_data + pos + len);
		}

		delete [] m_data;
		m_data = m_new_data;

		return *this;
	}

	// compare() function : only full string, no substring
	int compare (const string& str) const {
		return std::strcmp(m_data, str.m_data);
	}

	// append() function : basic one
	string& append (const string& str) {
		*this += str;
		return *this;
	}

	~string(){
		delete [] m_data;
		m_data = nullptr;
	}
	private : 
	 unsigned int m_size;
	 char * m_data{nullptr};
};

	inline std::ostream& operator<< (std::ostream& out , const CU::string& s){
		out << s.m_data;
		return out;
	}

	inline string operator+(const string& left, const string& right){
		string tmp(left);
		tmp += right;
		return tmp;
	}

	inline string& operator+=(string& left, const string& right){

		// Need to put this condition to increase size if needed to accomodate new string
		if (int s = (left.size() + right.size() + 1); s > left.m_size) {
			char* m_new_data = new char[s];
			std::strcpy(m_new_data, left.m_data);
			delete [] left.m_data;
			left.m_data  = m_new_data;
			left.m_size = s;
		}
		std::strcat(left.m_data,right.m_data);
		return left;
	}
}