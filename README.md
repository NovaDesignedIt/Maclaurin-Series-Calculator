# Maclaurin Series

## Purpose: 
You are employed by an architecture company to write code for a
building simulation. The company wants to model the start of the motion
response of a tall building hit by strong winds that set it in vibration that builds
up catastrophically. The following graph shows the vibration oscillations
growing catastrophically in time (along the x-axis) over a large number of
Oscillations:

![Alt Text](https://github.com/NovaDesignedIt/Maclaurin-Series-Calculator/blob/main/Screenshot%20from%202022-01-05%2020-07-07.png?raw=true)

The formula you will use for an approximation for the movement
D of the top of the building in meters with time t in seconds after the vibration
starts up is:

![Alt Text](https://github.com/NovaDesignedIt/Maclaurin-Series-Calculator/blob/main/equ.png)

In this application you will investigate the series approximation to the
motion for its accuracy over initial times up to 4 seconds after the start of
the vibration.



# Algorithm:
Determine the Maclaurin Series approximation to D(t) = etcos(t)
as a power series in t (all variables are doubles) as given in lectures up to the
first 7 non-zero terms (you need 7 for the truncation error
1 on 6 terms). Then
as often as the user wishes to repeat, allow the user to choose the number ofnon- zero terms (from 1 to 6) in the series approximation and what range
(between 0.0 and 4.0) of values of t to evaluate in 10 equal increments.
The purpose of the series approximation is to speed up its execution so no
functions are used in the evaluation of the terms of the series, whether they
be math library functions such as exp() or pow() etc., or any other function,
and terms such as x 3 for example are written explicitly in your code as x*x*x
and factorials are precalculated and written in as numbers.
