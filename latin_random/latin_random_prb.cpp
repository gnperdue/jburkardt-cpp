# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

# include "latin_random.hpp"

int main ( );
void test00 ( int *seed );
void test01 ( int *seed );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    LATIN_RANDOM_PRB tests the Latin Random Square routines.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int seed;
  int seed_save;

  timestamp ( );
  cout << "\n";
  cout << "LATIN_RANDOM_PRB:\n";
  cout << "  C++ version\n";
  cout << "  Test the LATIN_RANDOM library.\n";

  test00 ( &seed );

  seed_save = seed;
  test01 ( &seed );

  cout << "\n";
  cout << "LATIN_RANDOM_PRB:\n";
  cout << "  Repeat TEST01, but with different seed from first run.\n";

  test01 ( &seed );

  cout << "\n";
  cout << "LATIN_PRB:\n";
  cout << "  Repeat TEST01 with same seed as first run.\n";

  seed = seed_save;
  test01 ( &seed );
//
//  Terminate.
//
  cout << "\n";
  cout << "LATIN_RANDOM_PRB:\n";
  cout << "  Normal end of execution.\n";

  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test00 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    TEST00 tests GET_SEED, RANDOM_INITIALIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
{
  cout << "\n";
  cout << "TEST00\n";
  cout << "  GET_SEED returns a seed for the random number\n";
  cout << "  generator, based on the current time.\n";

  *seed = get_seed ( );

  cout << "\n";
  cout << "  GET_SEED returns SEED = " << *seed << "\n";

  return;
}
//****************************************************************************80

void test01 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests LATIN_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
{
# define DIM_NUM 2
# define POINT_NUM 10

  int i;
  int j;
  int k;
  int kk;
  double x[DIM_NUM*POINT_NUM];

  cout << "\n";
  cout << "TEST01\n";
  cout << "  LATIN_RANDOM chooses a Latin Square cell arrangement,\n";
  cout << "  and then chooses a random point from each cell.\n";
  cout << "\n";
  cout << "  Spatial dimension = " << DIM_NUM << "\n";
  cout << "  Number of points =  " << POINT_NUM << "\n";
  cout << "  Initial seed for UNIFORM = " << *seed << "\n";

  latin_random ( DIM_NUM, POINT_NUM, seed, x );

  cout << "\n";
  cout << "  The Latin Random Square points:\n";
  cout << "\n";

  for ( j = 0; j < POINT_NUM; j++ )
  {
    for ( i = 0; i < DIM_NUM; i++ )
    {
      cout << setw(10) << x[i+j*DIM_NUM] << "  ";
    }
    cout << "\n";
  }

  return;
# undef POINT_NUM
# undef DIM_NUM
}