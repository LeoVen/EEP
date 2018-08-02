/**
 * @file struct_in_struct.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 01/08/2018
 * 
 * Struct inside a struct
 */
#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;
using std::to_string;

struct s_teacher
{
	string name;
	double salary;
};

struct s_student
{
	string name;
	long age;
};

struct s_class
{
	long course_id;
	string course_name;
	struct s_teacher teacher;
	struct s_student student;

	friend std::ostream &operator<<(std::ostream &stream, const struct s_class &c)
	{
		return stream << "Course " << c.course_name << " [ " << c.course_id << " ] : Teached by " << c.teacher.name << " for the student " << c.student.name;
	}
};

int main(int argc, char const *argv[])
{
	struct s_class math_class = {101, "Applied Mathematics", {"Alan Turing", 355.0}, {"Mario Rogers", 21}};

	std::cout << math_class << std::endl;

	return 0;
}
