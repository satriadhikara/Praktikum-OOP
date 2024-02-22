#include "BunchOfKeys.hpp"

#include <iostream>

using namespace std;

BunchOfKeys::BunchOfKeys() { this->n_keys = 0; }

void BunchOfKeys::add() { n_keys++; }

void BunchOfKeys::shake() {
  if (n_keys > 1) {
    for (int i = 0; i < n_keys; i++) {
      cout << "krincing" << endl;
    }
  } else {
    cout << "Tidak terjadi apa-apa" << endl;
  }
}
