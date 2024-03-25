#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
int binarySearch(int arr[], int n, int key, unsigned step){
	int i, right, left;
	for (i = 0; i < n&&arr[i] < key; i += step);
	if (i < step){
		left = 0;
	}
	else{
		left = i - 1 - step;
	}
	if (n < i){
		right = n - 1;
	}
	else{
		right = i;
	}
	return binarySearch(arr, n, key, step);
}
int main(){
	int arr[] = { 18, 19, 22, 23, 29, 32, 41, 43, 69, 77, 80, 86, 90, 92, 95 };
	int target = 95;
	std::cout << "Tursene na posledniq element s posledovatelen algorithm:\n";
	auto start = steady_clock::now();
	for (int step : {1, 6, 10, 12, 15, 20, 50, 100, 200, 333, 800, 1000}){
		int position = binarySearch(arr,);
		if (position != -1){
			std::cout << "Step " << step << ": Elementut sus stoinost " << target << " e nameren na pozitsiq " << position << std::endl;
		}
		else{
			std::cout << "Step " << step << ": Elementut sus stoinost " << target << " ne e nameren v masiva." << std::endl;
		}
	}
	auto end = steady_clock::now();
	duration<double> elapsed_seconds = end - start;
	std::cout << "Vreme za izpulnenie: " << elapsed_seconds.count() << " seconds" << std::endl;

}