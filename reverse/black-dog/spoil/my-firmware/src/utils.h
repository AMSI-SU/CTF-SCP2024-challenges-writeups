#ifndef UTILS
#define UTILS

// OPERATOR funcs
volatile unsigned int div_int(volatile unsigned int dividend, volatile unsigned int divisor) {
    if (divisor == 0) return 0; // Division par zéro
    volatile unsigned int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}
volatile unsigned int mod(volatile unsigned int dividend, volatile unsigned int divisor) {
    if (divisor == 0) return 0; // Modulo par zéro, cas indéfini
    while (dividend >= divisor) {
        dividend -= divisor;
    }
    return dividend;
}

// FORMAT funcs
char itoh(volatile unsigned char i) {
    if(i > 0xf) {
        return 0;
    }
    else if(i >= 0xa) {
        return 'a'+i-10;
    }
    else {
        return '0'+i;
    }
}
char itoc(volatile unsigned char i) {
    if(i > 9) {
        return 0;
    }
    else {
        return '0'+i;
    }
}
// write the date in out buffer as "dd-mm-yyyy HH:MM:SS" (size=20)
void epoch_to_datestr(char * out, volatile unsigned int epoch) {
    // Définition des constantes pour les calculs
    volatile const unsigned int SECONDS_IN_A_DAY = 86400;
    volatile const unsigned int SECONDS_IN_AN_HOUR = 3600;
    volatile const unsigned int SECONDS_IN_A_MINUTE = 60;

    volatile const unsigned int SECONDS_IN_A_YEAR = 31536000;
    volatile const unsigned int SECONDS_IN_A_LEAP_YEAR = 31622400;

    const char days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    volatile unsigned int days = div_int(epoch, SECONDS_IN_A_DAY);
    volatile unsigned int seconds_remaining = mod(epoch, SECONDS_IN_A_DAY);
    volatile unsigned int year = 1970;

    // Calcul de l'année
    while (1) {
        int is_leap_year = (mod(year, 4) == 0 && (mod(year, 100) != 0 || mod(year, 400) == 0));
        volatile unsigned int days_in_year = is_leap_year ? 366 : 365;

        if (days < days_in_year) break;

        days -= days_in_year;
        year++;
    }

    // Calcul du mois et du jour
    volatile unsigned char month = 0;
    while (1) {
        volatile unsigned char days_this_month = days_in_month[month];
        if (month == 1 && (mod(year, 4) == 0 && (mod(year, 100) != 0 || mod(year, 400) == 0))) {
            days_this_month = 29; // Février bissextile
        }

        if (days < days_this_month) break;

        days -= days_this_month;
        month++;
    }

    volatile unsigned char day = days + 1; // Les jours commencent à 1
    month += 1;             // Les mois commencent à 1

    // Calcul de l'heure, minute, et seconde
    volatile unsigned char hours = div_int(seconds_remaining, SECONDS_IN_AN_HOUR);
    seconds_remaining = mod(seconds_remaining, SECONDS_IN_AN_HOUR);
    volatile unsigned char minutes = div_int(seconds_remaining, SECONDS_IN_A_MINUTE);
    volatile unsigned char seconds = mod(seconds_remaining, SECONDS_IN_A_MINUTE);

    // Affichage de la date et heure sous format "dd-mm-yyyy HH:MM:SS"
    out[0] = '0' + div_int(day, 10);
    out[1] = '0' + mod(day, 10);
    out[2] = '-';
    out[3] = '0' + div_int(month, 10);
    out[4] = '0' + mod(month, 10);
    out[5] = '-';
    out[6] = '0' + mod(div_int(year, 1000), 10);
    out[7] = '0' + mod(div_int(year, 100), 10);
    out[8] = '0' + mod(div_int(year, 10), 10);
    out[9] = '0' + mod(year, 10);
    out[10]= ' ';
    out[11]= '0' + div_int(hours, 10);
    out[12]= '0' + mod(hours, 10);
    out[13]= ':';
    out[14]= '0' + div_int(minutes, 10);
    out[15]= '0' + mod(minutes, 10);
    out[16]= ':';
    out[17]= '0' + div_int(seconds, 10);
    out[18]= '0' + mod(seconds, 10);
    out[19]= 0;
}

// SLEEP
void sleep(int n) {
    for (int i=0; i<n; i++);
}






#endif