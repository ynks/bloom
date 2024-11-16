/**
 * \file math_cli
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

void printMatrix(const catv::Matrix4& matrix);

int main()
{
  float values[4][4] = {
    {1.0f, 2.0f, 3.0f, 4.0f},
    {2.0f, 4.0f, 6.0f, 7.0f},
    {9.0f, 11.0f, 11.0f, 12.0f},
    {13.0f, 14.0f, 15.0f, 16.0f}
  };
  catv::Matrix4 matrix(values);

  std::cout << "\n original =\n";
  printMatrix(matrix);
  std::cout << "\n transpose =\n";
  printMatrix(matrix.Transpose());
  std::cout << "\n inverse =\n";
  printMatrix(matrix.Inverse());

  return 0;
}

void printMatrix(const catv::Matrix4& matrix) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << std::setw(10) << matrix(i,j) << " ";
    }
    std::cout << std::endl;
  }
}
