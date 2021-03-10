#include <vector>
#include <iostream>

inline std::vector<int> generate(std::vector<int> matrix, const std::size_t m, const std::size_t n);
inline void sort(std::vector<int>& matrix, const std::size_t m, const std::size_t n);

int main()
{
    /*Declaration and initialization of collums and rows indexs*/
    std::size_t m, n;
    std::cin >> m >> n;

    /*Matrix declaration, all field set to 0*/
    std::vector<int> matrix(m * n);

    std::cout << matrix.size() << std::endl;

    /*Matrix initialization*/
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            std::cin >> matrix[i * n + j];
    }

    std::vector<int> sorted_matrix = generate(matrix, m, n);
    for(int i = 0; i < m * n; ++i)
    {
        if(i % n == 0)
            std::cout << std::endl << sorted_matrix[i] << " ";
        else
            std::cout << sorted_matrix[i] << " ";
    }
    return 0;
}

/*generating new matrix that will be sorted and which copy will be returned*/
std::vector<int> generate(std::vector<int> matrix, const std::size_t m, const std::size_t n)
{
    std::vector<int> new_matrix(m * n);
    new_matrix = matrix;
    sort(new_matrix, m, n);
    return new_matrix;
}

/*Sorting matrix*/
void sort(std::vector<int>& matrix, const std::size_t m, const std::size_t n)
{
    int index = 0;
    int temp = 0;
    for(int col = 0; col < n; ++col)
    {
        for (int times = 0; times < n; ++times)
        {
            for (int num = 0; num < m; ++num)
            {
                index = col;
                while ((index < (m * (n - 1) + col)) && (matrix[index] < matrix[index + n]))
                {
                    temp = matrix[index];
                    matrix[index] = matrix[index + n];
                    matrix[index + n] = temp;
                    index += n;
                }
            }
        }
    }

    for (int row = 0; row < m; ++row)
    {
        for (int times = 0; times < n; ++times)
        {
            for (int num = n; num > 0; --num)
            {
                index = row * n + num - 1;
                while ((index > (row * n)) && (matrix[index] > matrix[index - 1]))
                {
                    temp = matrix[index];
                    matrix[index] = matrix[index - 1];
                    matrix[index - 1] = temp;
                    --index;
                }
            }
        }
    }
}
