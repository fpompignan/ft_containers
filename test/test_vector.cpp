#include <vector>
#include <iostream>
#include <chrono>


void	test_push()
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

void	test_empty()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	B.push_back(42);

	std::cout << "test de empty : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.pop_back();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.pop_back();
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A.empty() == 1 && B.empty() == 1)
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

void	test_size()
{
	std::vector<int> A;
	ft::vector<int>	 B;

	A.push_back(42);
	B.push_back(42);
	A.push_back(2);
	B.push_back(2);
	

	std::cout << "test de size : ";
	auto start = std::chrono::high_resolution_clock::now();
	A.pop_back();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_std = end - start;
	auto starts = std::chrono::high_resolution_clock::now();
	B.pop_back();
	auto ends = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_ft = ends - starts;
	if (A.size() == 1 && B.size() == 1)
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

void    test_equality()
{
        std::vector<int> A;
        ft::vector<int>  B;
        std::vector<int> C;
        ft::vector<int>  D;


        A.push_back(42);
        A.push_back(56);
        B.push_back(42);
        B.push_back(56);
        C.push_back(42);
        C.push_back(56);
        D.push_back(42);
        D.push_back(56);


        std::cout << "test de egalite : ";
        auto start = std::chrono::high_resolution_clock::now();
        if (A == C)
                std::cout << "";
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        if (B == D)
                std::cout << "";
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A == C && B == D)
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

void	test_vector()
{

        std::cout << "--------------------VECTOR--------------------------------\n";
        std::cout << "--------------------VECTOR--------------------------------\n";
        std::cout << "--------------------VECTOR--------------------------------\n";
        std::cout << "--------------------VECTOR--------------------------------\n";
        std::cout << "--------------------VECTOR--------------------------------\n";

	test_assignation();
	test_push();
	test_pop();
	test_clear();
	test_swap();
	test_erase();
	test_insert();
	test_empty();
	test_size();
	test_resize();
	test_reserve();
	test_iterator();
	test_equality();
}
