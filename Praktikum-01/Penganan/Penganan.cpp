#include "Penganan.hpp"

#include <iostream>

using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
  this->keik = 0;
  this->panekuk = 0;
}

Penganan::Penganan(int keik, int panekuk) {
  this->keik = keik;
  this->panekuk = panekuk;
}

int Penganan::GetKeik() const { return keik; }

int Penganan::GetPanekuk() const { return panekuk; }

void Penganan::SetKeik(int n) { keik = n; }

void Penganan::SetPanekuk(int n) { panekuk = n; }

Penganan operator+(const Penganan &a, const Penganan &b) {
  Penganan::n_rumah++;
  int hasilKeik = a.keik + b.keik;
  int hasilPanekuk = a.panekuk + b.panekuk;
  Penganan hasil(hasilKeik, hasilPanekuk);
  return hasil;
}

Penganan operator-(const Penganan &a, const Penganan &b) {
  int hasilKeik = a.keik - b.keik;
  if (hasilKeik < 0) {
    Penganan::uang += (a.keik * 51);
    hasilKeik = 0;
  } else {
    Penganan::uang += (b.keik * 51);
  }
  int hasilPanekuk = a.panekuk - b.panekuk;
  if (hasilPanekuk < 0) {
    Penganan::uang += (a.panekuk * 37);
    hasilPanekuk = 0;
  } else {
    Penganan::uang += (b.panekuk * 37);
  }
  Penganan hasil(hasilKeik, hasilPanekuk);
  return hasil;
}

Penganan operator^(const Penganan &other, const int n) {
  Penganan hasil;
  if (n > other.keik) {
    other.uang -= (n - other.keik) * 51;
    hasil.SetKeik(0);
  } else {
    hasil.SetKeik(other.keik - n);
  }
  if (n > other.panekuk) {
    other.uang -= (n - other.panekuk) * 37;
    hasil.SetPanekuk(0);
  } else {
    hasil.SetPanekuk(other.panekuk - n);
  }
  return hasil;
}

Penganan operator^(const int n, const Penganan &other) {
  Penganan hasil;
  if (n > other.keik) {
    other.uang -= (n - other.keik) * 51;
    hasil.SetKeik(0);
  } else {
    hasil.SetKeik(other.keik - n);
  }
  if (n > other.panekuk) {
    other.uang -= (n - other.panekuk) * 37;
    hasil.SetPanekuk(0);
  } else {
    hasil.SetPanekuk(other.panekuk - n);
  }
  return hasil;
}

int Penganan::JumlahUang() { return uang; }
int Penganan::HitungNRumah() { return n_rumah; }

void Penganan::Print() {
  cout << keik << "keik-" << panekuk << "panekuk" << endl;
}
