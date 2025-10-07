/*


*/

#include "Header.h"

int main(void)
{
	Employee employee_data[200];
	int number_of_employees = 0;
	double overtime[200], total_payroll_var = 0.0, average_payment = 0.0, max_payment_var = 0.0, min_payment_var = 0.0;
	FILE* input_stream = fopen("payroll.txt", "r");

	number_of_employees = collect_data(input_stream, employee_data);

	fclose(input_stream);

	compute_overtime(employee_data, number_of_employees, overtime);
	determine_payment(employee_data, number_of_employees, overtime);
	total_payroll_var = total_payroll(employee_data, number_of_employees);
	average_payment = total_payroll_var / (double)number_of_employees;
	max_payment_var = max_payment(employee_data, number_of_employees);
	min_payment_var = min_payment(employee_data, number_of_employees, max_payment_var);

	FILE* output_stream = fopen("paid.txt", "w");
	fprintf(output_stream, "Total: $%.2lf.\n", total_payroll_var);
	fprintf(output_stream, "Average: $%.2lf.\n", average_payment);
	fprintf(output_stream, "Max: $%.2lf.\n", max_payment_var);
	fprintf(output_stream, "Min: $%.2lf.\n", min_payment_var);

	fclose(output_stream);



	return 0;
}