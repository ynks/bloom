/**
 * \file math_cli.cpp
 * \author Xein <xgonip@gmail.com>
 * \date 16/11/2024
 *
 * \brief This file exists to test the math library
 */

#include <iomanip>
#include <iostream>

#include "catv/lintr.h"
#include "catv/matrix.h"
#include "catv/vector.h"

void printMatrix(const catv::Matrix3& matrix);
void printMatrix(const catv::Matrix4& matrix);

int main()
{
  std::cout << "\n Identity3 =\n";
  printMatrix(catv::matrix::Identity3);

  std::cout << "\n Identity4 =\n";
  printMatrix(catv::matrix::Identity4);

  return 0;
}

void printMatrix(const catv::Matrix4& matrix) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << std::setw(8) << matrix(i,j) << " ";
    }
    std::cout << std::endl;
  }
}
void printMatrix(const catv::Matrix3& matrix) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << std::setw(8) << matrix(i,j) << " ";
    }
    std::cout << std::endl;
  }
}
