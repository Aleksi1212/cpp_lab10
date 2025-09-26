#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class UniqueRng {
    public:
        UniqueRng(int min = 0, int max = 0) : min(min), max(max), numbers()
        {
            srand(time(NULL));
            range = max - min + 1;
            vector<int> v(range);
            iota(v.begin(), v.end(), min);

            availableNumbers = v;

        }
        int operator()() noexcept(false);
    private:
        int min;
        int max;
        int range;
        vector<int> numbers;
        vector<int> availableNumbers;
};

int UniqueRng::operator()()
{
    if (availableNumbers.empty()) {
        throw runtime_error("Unable to produce unique random.");
    }

    
    int number = rand() % range + min;
    numbers.push_back(number);

    availableNumbers.erase(find(availableNumbers.begin(), availableNumbers.end(), number));

    return number;
}

void test_generator(UniqueRng ur, int count)
{
    cout << "Generating numbers:" << endl;
    vector<int> numbers;

    int generated = 0;
    for (int i = 0; i < count; ++i) {
        try {
            numbers.push_back(ur());
            ++generated;
        } catch(const runtime_error& e) {
            cerr<< e.what()
                << " Tried to generate " << count << " random numbers."
                << " Got only " << generated
                << '\n';
            return;
        }
    }

    for (const auto num : numbers) {
        cout << num << endl;
    }
    cout << "End of generator." << endl;
}

int main(void)
{
    UniqueRng randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13); // this will cause exception

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70); // this will cause exception

    return 0;
}