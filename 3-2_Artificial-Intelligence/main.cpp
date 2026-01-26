#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <string.h>
#include <time.h>

#define total_data_size 70000
#define train_data_size 49000
#define test_data_size 21000

#define Hidden_node_size 100
#define epoch 110
#define learning_rate 0.15

using namespace std;

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
double diff_sigmoid(double x) { return (sigmoid(x) * (1.0 - sigmoid(x))); }

void load_data(vector<int>& train_Ans, vector<int>& Test_Ans, vector<vector<double>>& training_inputs, vector<vector<double>>& test_inputs) {
	ifstream file("MNIST.txt");
	int temp = -1;
	int count = -1;
	if (file.is_open()) {
		string word;
		cout << "Open \"MNIST.txt\" !! \n\n";

		cout << "Loading Training Data . . .\n";
		count = -1;
		for (int i = 0; i < train_data_size; i++) { // Training Data
			file >> word;
			train_Ans.push_back(stoi(word));

			vector<double> vec; vec.push_back(0);
			for (int j = 0; j < 784; j++) {
				file >> word;
				vec.push_back((double)stoi(word) / 255);
			}
			training_inputs.push_back(vec);

			if (i / (train_data_size / 10) != count) {
				cout << "|";
				count = i / (train_data_size / 10);
			}
		}
		cout << " 100% \n";

		cout << "Loading Test Data . . .\n";
		count = -1;
		for (int i = 0; i < test_data_size; i++) { // Test Data
			file >> word;
			Test_Ans.push_back(stoi(word));

			vector<double> vec; vec.push_back(0);
			for (int j = 0; j < 784; j++) {
				file >> word;
				vec.push_back((double)stoi(word) / 255);
			}
			test_inputs.push_back(vec);

			if (i / (test_data_size / 10) != count) {
				cout << "|";
				count = i / (test_data_size / 10);
			}
		}
		cout << " 100% \n";

		file.close();
	}
}

void Data_optimization(vector<vector<double>>& training_inputs, vector<vector<double>>& test_inputs) {
	cout << "Start Data_optimization \n";
	for (int i = 0; i < train_data_size; i++) {
		vector<double> temp_vec, result_vec; result_vec.push_back(0);
		for (int j = 0; j < 392; j++) {
			double temp = 0;
			temp = training_inputs[i][(j * 2)] + training_inputs[i][(j * 2) + 1];
			temp_vec.push_back(temp);
		}

		for (int j = 0; j < 196; j++) {
			double temp = 0;
			temp = temp_vec[((j / 14) * 2) * 14 + (j % 14)] + temp_vec[(j / 14) * 14 + (j % 14)];
			result_vec.push_back(temp);
		}

		for (int j = 0; j < 196; j++) 
			result_vec[j] /= 4.0f;

		training_inputs[i] = result_vec;
	}

	for (int i = 0; i < test_data_size; i++) {
		vector<double> temp_vec, result_vec; result_vec.push_back(0);
		for (int j = 0; j < 392; j++) {
			double temp = 0;
			temp = test_inputs[i][(j * 2)] + test_inputs[i][(j * 2) + 1];
			temp_vec.push_back(temp);
		}

		for (int j = 0; j < 196; j++) {
			double temp = 0;
			temp = temp_vec[((j / 14) * 2) * 14 + (j % 14)] + temp_vec[(j / 14) * 14 + (j % 14)];
			result_vec.push_back(temp);
		}

		for (int j = 0; j < 196; j++)
			result_vec[j] /= 4.0f;

		test_inputs[i] = result_vec;
	}
}

void init(double* input_node, double* hidden_node, double* output_node, double edge_input_hidden[785][Hidden_node_size + 1], double edge_hidden_output[Hidden_node_size + 1][10]) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
		output_node[i] = 0;

	for (int i = 0; i <= 196; i++)
		for (int j = 0; j <= Hidden_node_size; j++)
			edge_input_hidden[i][j] = (rand() % 2) - 0.5;

	for (int i = 0; i <= Hidden_node_size; i++)
		for (int j = 0; j < 10; j++)
			edge_hidden_output[i][j] = (rand() % 2) - 0.5;

	input_node[0] = 1;
	hidden_node[0] = 1.0;
}

void get_input(double* target, vector<vector<double>> source, int index) {
	for (int i = 1; i <= 196; i++) 
		target[i] = source[index][i];
}

int main() {
	vector<int> train_Ans, test_Ans;
	vector<vector<double>> training_inputs, test_inputs;
	load_data(train_Ans, test_Ans, training_inputs, test_inputs);
	Data_optimization(training_inputs, test_inputs);

	double input_node[197], hidden_node[Hidden_node_size + 1], output_node[10], edge_input_hidden[197][Hidden_node_size + 1], edge_hidden_output[Hidden_node_size + 1][10];
	init(input_node, hidden_node, output_node, edge_input_hidden, edge_hidden_output);

	double d_v[197][Hidden_node_size + 1];
	double d_w[Hidden_node_size + 1][10];
	double z_in[Hidden_node_size + 1];
	double y_in[10];
	double d_in[Hidden_node_size + 1];
	double d_k[10];
	double t[10];
	double d_j[Hidden_node_size + 1];

	cout << "Start training \n";
	for (int e = 0; e < epoch; e++) {
		cout << "epoch : " << e << "\t";
		// training
		int correct = 0;
		for (int index = 0; index < train_data_size; index++) {
			double max = 0;
			int predic = 0;
			get_input(input_node, training_inputs, index);
			/*
			for (int i = 0; i < 28; i++) {
				for (int j = 1; j <= 28; j++) {
					if (input[i * 28 + j] == 0)
						cout << "_._ ";
					else
						printf_s("%.1f ", input[i * 28 + j]);
				}
				cout << "\n";
			}
			*/

			for (int i = 0; i < 10; i++)
				t[i] = 0.0;
			t[train_Ans[index]] = 1.0;

			// cout << "Á¤´ä  : " << train_Ans[index] << "\n";
			for (int j = 1; j <= Hidden_node_size; j++) {
				z_in[j] = edge_input_hidden[0][j];
				for (int i = 1; i <= 196; i++)
					z_in[j] += (input_node[i] * edge_input_hidden[i][j]);
				hidden_node[j] = sigmoid(z_in[j]);
			}

			for (int k = 0; k < 10; k++) {
				y_in[k] = edge_hidden_output[0][k];

				for (int j = 1; j <= Hidden_node_size; j++)
					y_in[k] += (hidden_node[j] * edge_hidden_output[j][k]);

				output_node[k] = sigmoid(y_in[k]);
			}

			for (int k = 0; k < 10; k++) {
				y_in[k] = edge_hidden_output[0][k];
				for (int j = 1; j <= Hidden_node_size; j++)
					y_in[k] += (hidden_node[j] * edge_hidden_output[j][k]);
				output_node[k] = sigmoid(y_in[k]);
				if (output_node[k] > max) {
					max = output_node[k];
					predic = k;
				}
			}

			for (int k = 0; k < 10; k++) {
				d_k[k] = (t[k] - output_node[k]) * diff_sigmoid(y_in[k]);
				d_w[0][k] = learning_rate * d_k[k];
				for (int j = 1; j <= Hidden_node_size; j++)
					d_w[j][k] = learning_rate * d_k[k] * hidden_node[j];
			}

			for (int j = 1; j <= Hidden_node_size; j++) {
				d_in[j] = 0;
				for (int k = 0; k < 10; k++)
					d_in[j] += (d_k[k] * edge_hidden_output[j][k]);
				d_j[j] = d_in[j] * diff_sigmoid(z_in[j]);
			}

			for (int j = 1; j <= Hidden_node_size; j++)
				for (int i = 0; i <= 196; i++)
					d_v[i][j] = learning_rate * d_j[j] * input_node[i];

			for (int j = 1; j <= Hidden_node_size; j++)
				for (int k = 0; k < 10; k++)
					edge_hidden_output[j][k] += d_w[j][k];

			for (int i = 1; i <= 196; i++)
				for (int j = 1; j <= Hidden_node_size; j++)
					edge_input_hidden[i][j] += d_v[i][j];

			if (train_Ans[index] == predic)
				correct++;
		}

		cout << "Loss rate : " << ((double)(train_data_size - correct) / train_data_size) * 100 << "% \n";
	}

	// test
	int correct = 0;
	for (int num = 0; num < test_data_size; num++) { 
		double max = 0;
		int predic = 0;
		get_input(input_node, test_inputs, num);

		for (int j = 1; j <= Hidden_node_size; j++) {
			z_in[j] = edge_input_hidden[0][j];

			for (int i = 1; i <= 196; i++)
				z_in[j] += (input_node[i] * edge_input_hidden[i][j]);
			hidden_node[j] = sigmoid(z_in[j]);
		}

		for (int k = 0; k < 10; k++) {
			y_in[k] = edge_hidden_output[0][k];

			for (int j = 1; j <= Hidden_node_size; j++)
				y_in[k] += (hidden_node[j] * edge_hidden_output[j][k]);

			output_node[k] = sigmoid(y_in[k]);
			if (output_node[k] > max) {
				max = output_node[k];
				predic = k;
			}
		}

		if (test_Ans[num] == predic)
			correct++;
	}
	cout << "Loss rate : " << ((double)(test_data_size - correct) / test_data_size) * 100 << "% \n";
	cout << "Test Accuracy : " << ((double)correct / test_data_size) * 100 << "% \n";
}