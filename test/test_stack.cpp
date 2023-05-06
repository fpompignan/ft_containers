#include <stack>
#include <iostream>
#include <chrono>

void    test_top_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;

        std::cout << "test de top : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.push(42);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.push(42);
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.top() - B.top() == 0 && A.top() == 42)
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


void    test_push_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;

        std::cout << "test de push : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.push(42);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.push(42);
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.top() - B.top() == 0 && A.top() == 42)
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

void    test_pop_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;

        A.push(42);
        A.push(56);
        B.push(42);
        B.push(56);

        std::cout << "test de pop : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.pop();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.pop();
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.top() == B.top() && A.top() == 42)
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

void    test_empty_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;

        A.push(42);
        B.push(42);

        std::cout << "test de empty : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.pop();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.pop();
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

void    test_size_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;

        A.push(42);
        A.push(56);
        B.push(42);
        B.push(56);

        std::cout << "test de size : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.size();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.size();
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.size() == 2 && B.size() == 2)
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

void    test_equality_stack()
{
        std::stack<int> A;
        ft::stack<int>  B;
	std::stack<int> C;
        ft::stack<int>  D;


        A.push(42);
        A.push(56);
        B.push(42);
        B.push(56);
	C.push(42);
        C.push(56);
        D.push(42);
        D.push(56);


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

void	test_stack()
{
	std::cout << "--------------------STACK--------------------------------\n";
	std::cout << "--------------------STACK--------------------------------\n";
	std::cout << "--------------------STACK--------------------------------\n";
	std::cout << "--------------------STACK--------------------------------\n";
	std::cout << "--------------------STACK--------------------------------\n";

	test_top_stack();
	test_push_stack();	
	test_pop_stack();
	test_empty_stack();
	test_size_stack();
	test_equality_stack();
}
