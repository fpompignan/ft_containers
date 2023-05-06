#include <map>
#include <iostream>
#include <chrono>



void    test_insert_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	std::pair<std::string, int> p1("hello", 42);
	ft::pair<std::string, int> p2("hello", 42);

        std::cout << "test de insert : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.insert(p1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.insert(p2);
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A["hello"] == B["hello"])
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

void    test_erase_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;
	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
        std::cout << "test de erase : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.erase("bye");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.erase("bye");
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.size() == B.size())
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_clear_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
	
        std::cout << "test de clear : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.clear();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.clear();
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A.size() == B.size() && A.size() == 0)
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_swap_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;
        std::map<std::string,int> C;
        ft::map<std::string, int>  D;
	A["hello"] = 42;
	B["hello"] = 42;
	C["A"] = 1;
	D["A"] = 1;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	C["B"] = 2;
	C["B"] = 2;
	A["salut"] = 84;
	B["salut"] = 84;
	C["C"] = 3;
	D["C"] = 3;
	A["bye"] = 55;
	B["bye"] = 55;
	C["D"] = 4;
	D["D"] = 4;
	
        std::cout << "test de swap : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.swap(C);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.swap(D);
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (A["A"] == B["A"] && A["A"] == 1)
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_find_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
	
        std::cout << "test de find : ";
	std::map<std::string, int>::iterator it1;
        auto start = std::chrono::high_resolution_clock::now();
        it1 = A.find("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
	ft::map<std::string, int>::iterator it2;
        auto starts = std::chrono::high_resolution_clock::now();
        it2 = B.find("hello");
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if ( (*it1).first == "hello" && (*it2).get_key() == "hello")
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_count_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
	
        std::cout << "test de count : ";
        auto start = std::chrono::high_resolution_clock::now();
        size_t num1 = A.count("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        size_t num2 = B.count("hello");
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if ( num1 == num2 && num1 == 1)
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_lower_bound_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
	
        std::cout << "test de lower_bound : ";
	std::map<std::string, int>::iterator it1;
        auto start = std::chrono::high_resolution_clock::now();
        it1 = A.lower_bound("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
	ft::map<std::string, int>::iterator it2;
        auto starts = std::chrono::high_resolution_clock::now();
        it2 = B.lower_bound("hello");
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if ( (*it1).first == "hello" && (*it2).get_key() == "hello")
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}

void    test_upper_bound_map()
{
        std::map<std::string,int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;
	A["bye"] = 5;
	B["bye"] = 5;
	
        std::cout << "test de upper_bound : ";
	std::map<std::string, int>::iterator it1;
        auto start = std::chrono::high_resolution_clock::now();
        it1 = A.upper_bound("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
	ft::map<std::string, int>::iterator it2;
        auto starts = std::chrono::high_resolution_clock::now();
        it2 = B.upper_bound("hello");
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if ( (*it1).first == "salut" && (*it2).get_key() == "salut")
                std::cout << "OK\n";
        else
                std::cout << "error\n";
	//std::cout << B;
        std::cout << "temps std :" << time_std.count() << std::endl;
        std::cout << "temps ft :" << time_ft.count() << std::endl;
        if (time_ft > 20 * time_std)
                std::cout << "time execution : Too slow" << std::endl;
        else
                std::cout << "time execution : OK\n";
        std::cout << "--------------------------------------------------\n";

}


void    test_assignation_map()
{
        std::map<std::string, int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;


        std::map<std::string,int> C;
        ft::map<std::string, int>  D;



        std::cout << "test de assignation : ";
        auto start = std::chrono::high_resolution_clock::now();
        C = A;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        D = B;
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if (C["hello"] == 42 && C["salut"] == 84 && D["hello"] == 42 && D["salut"] == 84)
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

void    test_iterator_map()
{
        std::map<std::string, int> A;
        ft::map<std::string, int>  B;

	A["hello"] = 42;
	B["hello"] = 42;
	A["bonjour"] = 21;
	B["bonjour"] = 21;
	A["salut"] = 84;
	B["salut"] = 84;

        std::cout << "test d'iteration : ";
        auto start = std::chrono::high_resolution_clock::now();
        std::map<std::string, int>::iterator it1(A.begin());
        it1++;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;

        auto starts = std::chrono::high_resolution_clock::now();
        ft::map<std::string, int>::iterator it2(B.begin());
        it2++;
        auto ends = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ft = ends - starts;
        if  ( (*it1).first == "hello" && (*it2).get_key() == "hello")
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

void    test_empty_map()
{
        std::map<std::string, int> A;
        ft::map<std::string, int>  B;

        A["hello"] = 42;
        B["hello"] = 42;

        std::cout << "test de empty : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.erase("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.erase("hello");
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

void    test_size_map()
{
        std::map<std::string, int> A;
        ft::map<std::string, int>  B;

        A["hello"] = 42;
        B["hello"] = 42;
	A["hllo"] = 2;
        B["hllo"] = 2;
	

        std::cout << "test de size : ";
        auto start = std::chrono::high_resolution_clock::now();
        A.erase("hello");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_std = end - start;
        auto starts = std::chrono::high_resolution_clock::now();
        B.erase("hello");
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



void    test_equality_map()
{
        std::map<std::string, int> A;
        ft::map<std::string, int>  B;
	std::map<std::string, int> C;
        ft::map<std::string, int>  D;


        A["hello"] = 42;
        B["hello"] = 42;
	A["coucou"] = 2;
	B["coucou"] = 2;
	C["hello"] = 42;
        D["hello"] = 42;
	C["coucou"] = 2;
	D["coucou"] = 2;


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
void test_map()
{
	std::cout << std::endl;
	std::cout << "--------------MAP----------------------\n";
	std::cout << "--------------MAP----------------------\n";
	std::cout << "--------------MAP----------------------\n";
	std::cout << "--------------MAP----------------------\n";
	std::cout << std::endl;

	test_insert_map();
	test_erase_map();
	test_clear_map();
	test_swap_map();
	test_find_map();
	test_count_map();
	test_lower_bound_map();
	test_upper_bound_map();
	test_assignation_map();
	test_iterator_map();
	test_empty_map();
	test_size_map();
	test_equality_map();


}


