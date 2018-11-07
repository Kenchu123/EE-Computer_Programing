double potential_energy();
void kinetic_energy(int, double);


double max_value(double num)
{
    double max=-1;
    max = (num>max) ? num : max;
    return max;
}