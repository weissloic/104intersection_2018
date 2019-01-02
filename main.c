/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include <math.h>

int my_str_isnum(char const *str)
{
  if (*str == '-')
    str++;
  while (*str)
    {
      if (*str < '0' || '9' < *str)
    return (0);
      str++;
    }
  return (1);
}


int main(int ac, char **av)
{

    int i = 1;

    if (ac != 9){
        printf("Invalid number of arg");
        exit(84);
    }

    int deter = atoi(av[1]);
    int argv2 = atoi(av[2]);
    int argv3 = atoi(av[3]);
    int argv4 = atoi(av[4]);
    int argv5 = atoi(av[5]);
    int argv6 = atoi(av[6]);
    int argv7 = atoi(av[7]);
    int parameter = atoi(av[8]);
    float rayon = (M_PI / 2 - parameter * M_PI / 180);
    float racine_1;
    float racine_2;
    float delta;
    float a_calc;
    float b_calc;
    float c_calc;

    if (parameter < 0 || parameter > 360)
        exit (84);

    while (i != 9) {
        if (my_str_isnum(av[i]) != 1) {
            printf("Invalid formats of arguments.\n");
            return (84);
        }
        i++;
    }

    if (deter == 1) {
        printf("Sphere of radius %d\n", parameter);
        printf("Line passing throught the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", argv2, argv3, argv4, argv5, argv6, argv7);
        a_calc = pow(argv5, 2) + pow(argv6, 2) + pow(argv7, 2);
        b_calc = (2 * argv2 * argv5) + (2 * argv3 * argv6) + (2 * argv4 * argv7);
        c_calc = ((pow(argv2, 2) + pow(argv3, 2) + pow(argv4, 2)) - (pow(parameter, 2)));
    }

    else if (deter == 2) {
        printf("Cylinder of radius %d\n", parameter);
        printf("Line passing throught the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", argv2, argv3, argv4, argv5, argv6, argv7);
        a_calc = pow(argv5, 2) + pow(argv6, 2);
        b_calc = (2 * argv2 * argv5) + (2 * argv3 * argv6);
        c_calc = pow(argv2, 2) + pow(argv3, 2) - pow(parameter, 2);
    }


    else if (deter == 3) {
        printf("Cylinder of radius %d\n", parameter);
        printf("Line passing throught the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", argv2, argv3, argv4, argv5, argv6, argv7);
        a_calc = pow(tan(M_PI / 2 - parameter * M_PI / 180), 2) * (pow(argv5, 2) + pow(argv6, 2)) - pow(argv7, 2);
        b_calc = pow(tan(M_PI / 2 - parameter * M_PI / 180), 2) * (2 * argv2 * argv5 + 2 * argv3 * argv6) - (2 * argv4 * argv7);
        c_calc = pow(tan(M_PI / 2 - parameter * M_PI / 180), 2) * (pow(argv2, 2) + pow(argv3, 2)) - pow(argv4, 2);
    }
    else 
        exit (84);

    delta = pow(b_calc, 2) - (4 * a_calc * c_calc);

    /*if (delta <= 0 && deter == 2)
        printf("Point infinit");
        printf("Cone with a %d degree angle\n", parameter);
        printf("Line passing throught the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", argv2, argv3, argv4, argv5, argv6, argv7);
*/
    if (delta == 0) {
        printf("1 intersection point:\n");
        racine_1 = -b_calc / (2 * a_calc);
        printf("(%.3f, %.3f, %.3f)\n", argv2 + racine_1 * argv5, argv3 + racine_1 * argv6, argv4 + racine_1 * argv7);
    }
    else if (delta < 0)
        printf("No intersection point.\n");

    else if (delta > 0) {
        printf("2 intersection points:\n");
        racine_1 = (-b_calc - sqrt(delta)) / (2 * a_calc);
        racine_2 = (-b_calc + sqrt(delta)) / (2 * a_calc);
        printf("(%.3f, %.3f, %.3f)\n", argv2 + racine_2 * argv5, argv3 + racine_2 * argv6, argv4 + (racine_2 * argv7));
        printf("(%.3f, %.3f, %.3f)\n", argv2 + racine_1 * argv5, argv3 + racine_1 * argv6, argv4 + (racine_1 * argv7));
        
    }
    return (0);
}