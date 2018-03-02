def fall(cap=1):
    import math

    R_Earth = 6371000
    M_Earth = 5.972 * 10 ** 24
    G = 6.674 * 10 ** -11

    rho = M_Earth / ((4.0 / 3) * math.pi * R_Earth ** 3)

    inc = R_Earth / 4.0

    while inc >= cap:

        x = R_Earth
        a = G * rho * (4 / 3.0) * math.pi * x
        t = 0.0
        v = 0.0

        while x > 0:
            u = v
            v = (u ** 2 + 2 * a * inc) ** 0.5
            t = t + (v - u) / a
            x = x - inc
            a = G * rho * (4 / 3.0) * math.pi * x

        print(
        'Inc of {0} m gave a time of {1} s and max speed of {2} m/s'.format(inc, t * 2, v))

        if inc / 2.0 < 1000:  # I wanted to double the number of incraments until they are 1km ish each
            if inc > 1000:
                inc = 1000
            else:  # Then I want to go down 1km, 100m, 10m etc
                inc = inc / 10.0
        else:
            inc = inc / 2.0

    return 'DONE'

fall()