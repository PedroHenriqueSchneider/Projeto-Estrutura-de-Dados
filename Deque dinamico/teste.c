#include <check.h>
#include "fila.h"
#include "lista.h"

// fila

// insere inicio
START_TEST(test_aluno_insere_fila)
{
    Fila h;
    initialize(&h, 1);
    ck_assert_int_eq(insere(&h, 801490), 801490);
}
END_TEST

START_TEST(test_aluno_remove_fila)
{
    Fila h;
    initialize(&h, 1);
    insere(&h, 801490);
    ck_assert_int_eq(retira(&h), 801490);
}
END_TEST

START_TEST(test_aluno_vazio_fila)
{
    Fila h;
    initialize(&h, 1);
    ck_assert_int_eq(vaziaF(&h), 1);
}
END_TEST

START_TEST(test_aluno_teste_fila)
{
    Fila h;
    int n = 10;
    initialize(&h, n);
    for (int i = 0; i < n; i++)
    {
        insere(&h, i);
    }
    for (int i = 0; i < n; i++)
    {
        ck_assert_int_eq(retira(&h), i);
    }
    ck_assert_int_eq(vaziaF(&h), 0);
}
END_TEST

START_TEST(test_aluno_teste_fila2)
{
    Fila h;
    int n = 10;
    initialize(&h, 5);
    for (int i = 0; i < n; i++)
    {
        insere(&h, i);
    }
    ck_assert_int_eq(cheia(&h), 1);
}
END_TEST

START_TEST(test_aluno_insereInicio_lista)
{
    listaEncadeada l;
    inicializar(&l);
    ck_assert_int_eq(insereI(&l, 800467), 800467);
}
END_TEST

START_TEST(test_aluno_insereFim_lista)
{
    listaEncadeada l;
    inicializar(&l);
    ck_assert_int_eq(insereF(&l, 800467), 800467);
}
END_TEST

START_TEST(test_aluno_removeInicio_lista)
{
    listaEncadeada l;
    inicializar(&l);
    insereI(&l, 800467);
    ck_assert_int_eq(removeI(&l), 800467);
}
END_TEST

START_TEST (test_aluno_removeFim_lista)
{
    listaEncadeada l;
    inicializar(&l);
    insereF(&l, 800467);
    ck_assert_int_eq(removeF(&l), 800467);
}
END_TEST

START_TEST (test_aluno_teste_lista)
{
    listaEncadeada l;
    int n = 10;
    inicializar(&l);
    for (int i = 0; i < n/2; i++)
    {
        insereI(&l, i);
        insereF(&l, i+1);
    }
    for (int i = 0; i < n; i++)
    {
        ck_assert_int_eq(removeI(&l), i);
        ck_assert_int_eq(removeF(&l), i+1);
    }
    ck_assert_int_eq(vaziaL(&l), 0);
}
END_TEST

Suite *create_fila_suite()
{
    Suite *s;
    TCase *tc_fila, *tc_lista;

    s = suite_create("Aluno");
    tc_fila = tcase_create("Fila");
    tc_lista = tcase_create("Lista");
    tcase_add_test(tc_fila, test_aluno_insere_fila);
    tcase_add_test(tc_fila, test_aluno_remove_fila);
    tcase_add_test(tc_fila, test_aluno_vazio_fila);
    tcase_add_test(tc_fila, test_aluno_teste_fila);
    tcase_add_test(tc_fila, test_aluno_teste_fila2);
    tcase_add_test(tc_lista, test_aluno_insereInicio_lista);
    tcase_add_test(tc_lista, test_aluno_insereFim_lista);
    tcase_add_test(tc_lista, test_aluno_removeInicio_lista);
    tcase_add_test(tc_lista, test_aluno_removeFim_lista);
    tcase_add_test(tc_lista, test_aluno_teste_lista);
    suite_add_tcase(s, tc_fila);
    suite_add_tcase(s, tc_lista);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = create_fila_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return 0;
}

