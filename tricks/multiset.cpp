//MULTISET - erase a single element

int value;
multiset<int> ms;

if (ms.find(value) != ms.end()) {
            ms.erase(ms.find(value)); //ms.erase(ms.lower_bound(value));
}
