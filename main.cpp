#include <iostream>

using namespace std;

void asd(int num) {
    int min = 10000;
    int max = -10000;

    int temp;
    while(num > 0) {
        temp = num % 10;
        num /= 10;

        if(temp > max)
            max = temp;
        if(temp < min)
            min = temp;
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

int main() {
    int num;
    for (int i = 0; i < 3; ++i) {
        cin >> num;
        asd(num);
    }
    return 0;
}