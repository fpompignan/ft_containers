#include <vector>
#include <stack>
#include <iostream>
#include <chrono>
#include "Vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "test/test_vector.cpp"
#include "test/test_map.cpp"
#include "test/test_stack.cpp"

int main()
{
	test_vector();
	test_map();
	test_stack();


	/*ft::stack<int> S;
	ft::stack<int> T;
	
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);

	T.push(42);
	std::cout << "T != S  :" << (T != S) <<std::endl;
	*/
	return (0);
}



/*int main()
{
	ft::pair<std::string, int> p("dodi", 666);
	//ft::pair2<std::string, int> p("hello", 21);
	//ft::MapNode<std::string, int> node(p);
	//ft::mapIterator<std::string, int>	iter(&node);
	//ft::map<std::string, int> tree2(tree);

	ft::map<std::string, int> tree;
	tree["hello"] = 42;
	tree["bonjour"] = 21;
	
	ft::map<std::string, int> tree2;
	tree2["dodi"] = 1;
	tree2["dodo"] = 2;
	tree2["dodu"] = 3;
	tree2["doda"] = 4;

	tree2["popo"] = 666;


	ft::swap(tree, tree2);

	std::cout << tree;
	

	for (ft::mapIterator<std::string, int> it= tree.begin(); it != tree.end(); it++)
		std::cout << *it << std::endl;
	std::cout << " size tree : " << tree.size() << std::endl;

	std::cout << "------------------------------------------------\n";

	for (ft::mapIterator<std::string, int> it= tree2.begin(); it != tree2.end(); it++)
		std::cout << *it << std::endl;
	std::cout << " size tree2 : " << tree2.size() << std::endl;


	return (0);
}*/


/*void	test_push()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	std::cout << "test de push_back : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.push_back(42);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.push_back(42);
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A[0] - B[0] == 0)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";

}

void	test_pop()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de pop_back : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.pop_back();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.pop_back();
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A[0] - B[0] == 0)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_clear()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de clear : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.clear();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.clear();
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A.empty() && B.empty())
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_swap()
{
	ft::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(33);
	B.push_back(33);

	std::cout << "test de swap : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.swap(B);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;

	std::vector<int> C;
	std::vector<int> D;

	C.push_back(42);
	C.push_back(56);
	D.push_back(33);
	D.push_back(33);

	auto starts = std::chrono::high_resolution_clock::now();
	C.swap(D);
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A[0] == C[0] && B[0] == D[0])
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_erase()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de erase : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.erase(A.begin());
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.erase(B.begin());
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A[0] == B[0] && A[0] == 56)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_insert()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de insert : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.insert(A.begin() + 1, 98);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.insert(B.begin() + 1, 98);
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A[1] - A[2] - A[0] == 0 && B[1] - B[2] - B.at(0) == 0)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_resize()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de resize : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.resize(5,1);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.resize(5,1);
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A.size() == 5 && B.size() == 5 && A[4] ==1 && B[4] == 1)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_assignation()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::vector<int> C;
	ft::vector<int>	 D;



	std::cout << "test de assignation : ";
	auto start = std::chrono::high_resolution_clock::now();
	C = A;
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	D = B;
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (C[0] == 42 && C[1] == 56 && D[0] == 42 && D[1] == 56)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_reserve()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test de reserve : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.reserve(15);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.reserve(15);
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A.capacity() == 15 && B.capacity() == 15)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}

void	test_iterator()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	A.push_back(56);
	B.push_back(42);
	B.push_back(56);

	std::cout << "test d'iteration : ";
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<int>::iterator it1(A.begin());
	it1++;
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;

	auto starts = std::chrono::high_resolution_clock::now();
	ft::vector<int>::iterator it2(B.begin());
	it2++;
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if  ( *it1 == 56 && *it2 == 56)
		std::cout << "OK\n";
	else
		std::cout << "error\n";

	std::cout << "temps std :" << time_std.count() << std::endl;
	std::cout << "temps ft :" << time_ft.count() << std::endl;
	if (time_ft > 20 * time_std)
		std::cout << "time execution : Too slow" << std::endl;
	else
		std::cout << "time execution : OK\n";
	std::cout << "--------------------------------------------------\n";
}
*/
