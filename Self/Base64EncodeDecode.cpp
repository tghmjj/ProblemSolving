#include <iostream>
using namespace std;
char base64_ascii[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" };
int MSB_Buffer[24];
bool is_Null_Buffer[24];
void buffer_clear() {
	for (int i = 0; i < 24; i++) {
		MSB_Buffer[i] = 0;
		is_Null_Buffer[i] = false;
	}
}
void put_in_buffer_E(char c, int index) {
	int Value = c - 0;
	int counter = 128;
	if (c == '\0') {
		for (int i = index; i < index + 8; i++) {
			is_Null_Buffer[i] = true;
		}
		return;
	}
	for (int i = index; i < index + 8; i++) {
		if (Value / counter == 1) {
			MSB_Buffer[i] = 1;
			Value -= counter;
		}
		counter /= 2;
	}
}
void put_in_buffer_D(char c,int index) {
	char* ptr = strstr(base64_ascii, &c);
	int Value = ptr-base64_ascii;
	int counter = 32;
	if (c == '=') {
		for (int i = index; i < index + 6; i++) {
			is_Null_Buffer[i] = true;
		}
		return;
	}
	for (int i = index; i < index + 6; i++) {
		if (Value / counter == 1) {
			MSB_Buffer[i] = 1;
			Value -= counter;
		}
		counter /= 2;
	}

}
char get_from_buffer_E(int index) {
	int base64_c_index=0;
	if (is_Null_Buffer[index]) {
		return '=';
	}
	int weight = 32;
	for (int i = index; i < index + 6;i++) {
		base64_c_index += MSB_Buffer[i] * weight;
		weight /= 2;
	}
	return base64_ascii[base64_c_index];
}
char get_from_buffer_D(int index) {
	int base64_c = 0;
	if (is_Null_Buffer[index]) {
		return '\0';
	}
	int weight = 128;
	for (int i = index; i < index + 8; i++) {
		base64_c += MSB_Buffer[i] * weight;
		weight /= 2;
	}
	return (char)base64_c;
}
char* Encode(char* arr) {
	int answer_len;
	if (strlen(arr) % 3 != 0) {
		answer_len = (strlen(arr) + (3 - (strlen(arr) % 3))) / 3 * 4;
	}
	else {
		answer_len = strlen(arr)/3*4;
	}
	char* answer = new char[answer_len+1];
	int answer_index=0;
	for (int i = 0; i < strlen(arr); i += 3) {
		//bytes to binary
		for (int j = i; j < i + 3; j++) {
			put_in_buffer_E(arr[j], (j % 3) * 8);
		}
		//Encoding
		for (int j = 0; j < 4; j++) {
			answer[answer_index] = get_from_buffer_E(j*6);
			answer_index++;
			if (answer_index >= answer_len)
			{
				answer[answer_index] = '\0';
				return answer;
			}
		}
		buffer_clear();
	}
	return answer;
}
char* Decode(char* arr) {
	int answer_len = strlen(arr) / 4 * 3;
	char* answer = new char[answer_len + 1];
	int answer_index = 0;
	
	for (int i = 0; i < strlen(arr); i+=4) {
		for (int j = i; j < i+4; j++) {
			put_in_buffer_D(arr[j], (j % 4) * 6);
		}

		for (int j = 0; j < 3; j++) {
			answer[answer_index] = get_from_buffer_D(j*8);
			answer_index++;
			if (answer_index >= answer_len) {
				answer[answer_index] = '\0';
				return answer;
			}
		}

		buffer_clear();
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/**************/
	char c;

	cout << "> Input mode (E: Encode, D : Decode, Q :Quit )\n";
	
	while (cin >> c) {
		char c_arr[1001];
		buffer_clear();
		getchar();
		cin.getline(c_arr, 100);
		switch (c)
		{
		case 'E':
			cout << "> Result : " << Encode(c_arr) << "\n\n";
			break;
		case 'D':
			cout << "> Result : " << Decode(c_arr) << "\n\n";
			break;
		case 'Q':return 0;
		default:
			break;
		}

		cout << "> Input mode (E: Encode, D : Decode, Q :Quit )\n";
	}

	/**************/
	return 0;
}

