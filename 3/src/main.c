#include "../inc/io.h"
#include "../inc/operations.h"
#include "../inc/alloc.h"
#include "../inc/check_time.h"
#include <string.h>
/*
Вариант 3 (14 % 6 + 1)
    Разреженная (содержащая много нулей) матрица хранится в форме 3-х объектов:
        - вектор A содержит значения ненулевых элементов;
        - вектор JA содержит номера столбцов для элементов вектора A;
        - связный список IA, в элементе Nk которого находится номер компонент
           в A и JA, с которых начинается описание строки Nk матрицы A.
     1. Смоделировать операцию умножения матрицы и вектора-столбца,
    хранящихся в этой форме, с получением результата в той же форме.
     2. Произвести операцию умножения, применяя стандартный алгоритм работы с
    матрицами.
     3. Сравнить время выполнения операций и объем памяти при использовании
    этих 2-х алгоритмов при различном проценте заполнения матриц
*/


int main(int argc, char **argv)
{
    int err_code = NO_ERRS;

    matrix_t matrix = {.n = 0, .m = 0, .data = NULL};
    vector_t vector = {.n = 0, .data = NULL};
    matrix_t result = {.n = 0, .m = 0, .data = NULL};
    
    sparse_matrix_t m_sparse = {.n = 0, .m = 0, .count = 0, .ind_cols = NULL, .data = NULL, .components = NULL};
    sparse_vector_t v_sparse = {.n = 0, .count = 0, .ind_cols = NULL, .data = NULL};
    sparse_matrix_t res_sparse = {.n = 0, .m = 0, .count = 0, .ind_cols = NULL, .data = NULL, .components = NULL};

    if (argc >= 4 && !strcmp(argv[1], "file"))
    {
        if (!(err_code = read_file_matrix(&matrix, argv[2])))
            err_code = read_file_vector(&vector, argv[3]);
    }
    else if (argc >= 4 && !strcmp(argv[1], "random"))
    {
        if (!(err_code = random_matrix(&matrix, argv[2], argv[3])))
            err_code = random_vector(&vector, argv[2], argv[3]);
    }
    else if (argc >= 2 && !strcmp(argv[1], "standart"))
    {
        if (!(err_code = input_matrix(&matrix)))
            err_code = input_vector(&vector);
    }
    else if (argc >= 2 && !strcmp(argv[1], "sparse"))
    {
        if (!(err_code = input_m_sparse(&m_sparse)))
            err_code = input_v_sparse(&v_sparse);
    }
    else
        err_code = ERR_ARG;
    
    if (!err_code && matrix.data)
        if (!(err_code = parse_matrix(&matrix, &m_sparse)))
            err_code = parse_vector(&vector, &v_sparse);

    if (!err_code)
    {
        mark_time(&matrix, &vector, &result, &m_sparse, &v_sparse, &res_sparse);

    
        puts("=============================================");
        output_matrix(&matrix);
        puts("=============================================");
        output_vector(&vector);
        puts("=============================================");
        output_m_sparse(&m_sparse);
        puts("=============================================");
        output_v_sparse(&v_sparse);
        puts("=============================================");
        output_matrix(&result);
        puts("=============================================");
        output_m_sparse(&res_sparse);
        puts("=============================================");
    }
    else
        print_error(err_code);

    free_matrix(&matrix);
    free_vector(&vector);
    free_matrix(&result);

    free_m_sparse(&m_sparse);
    free_v_sparse(&v_sparse);
    free_m_sparse(&res_sparse);

    return err_code;
}
