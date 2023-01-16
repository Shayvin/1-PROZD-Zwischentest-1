#include <stdio.h>

int main() {
    double zt = 0, at = 0, ue = 0;
    double sum_zt = 0, sum_at = 0, sum_ue = 0, sum_result = 0, sum_at_zt = 0;
    double pkt_sum = 0;
    double pkt_percent = 0;
    char input = 0; // Abgabetyp
    int i_at = 0, grade;

    while (input != '=') // Solange kein '=' eingegeben wird, läuft die Schleife
    {
        printf("\nZT Punkte: %.2lf", sum_zt);
        printf("\nAT Punkte: %.2lf", sum_at);
        printf("\nUE Punkte: %.2lf", sum_ue);
        printf("\nErreichbare Gesamtpunkte: %.2lf", sum_result);
        printf("\nTyp: ");
        scanf(" %c", &input); // Abgabetyp wird eingelesen

        if (input == 'z')
        {
            printf("\nPunkte: ");
            scanf("%lf", &zt);
            if (zt >= 0 && zt <= 10)
            {
                sum_result += 10;
                sum_zt += zt;
            } else
            {
                printf("\nungueltiger Bereich: min 0.00, max 10.00");
            }
        }

        if (input == 'a')
        {
            if (i_at == 0)
            {
                printf("\nPunkte: ");
                scanf("%lf", &at);
                if (at >= 0 && at <= 70)
                {
                    ++i_at;
                    sum_result += 70;
                    sum_at += at;
                }
                else
                {
                    printf("\nungueltiger Bereich: min 0.00, max 70.00");

                }

            }
            else
            {
                printf("\nnur ein Abschlusstest erlaubt");
            }
        }
        if (input == 'u')
        {
            printf("\nPunkte: ");
            scanf("%lf", &ue);
            if (ue >= 0 && ue <= 0.5)
            {
                sum_ue += ue;
                if (sum_ue > 10)
                {
                    sum_ue = 10;
                }
            }
            else
            {
                printf("\nungueltiger Bereich: min 0.00, max 0.50");
            }
        }
    }

    if(sum_result == 0) // Wenn sum_result = 0 ist, dann printed er eine Ausgabe mit den Werten 0
    {
        printf("\nGesamtpunkte absolut: 0.00");
        printf("\nGesamtpunkte %%: 0.00 %%");
        printf("\nNote: 0");
    }
    if(sum_result != 0)
    {
        pkt_sum = sum_at + sum_zt + sum_ue; // Gesamtsumme aus ZT, AT & UE
        sum_at_zt = sum_at + sum_zt; // Gesamtsumme aus ZT & AT
        pkt_percent = pkt_sum / sum_result * 100; // Gesamtpunkte in % (für Note 1-4)

        if(sum_at_zt / sum_result * 100 < 55)
        {
            pkt_sum = sum_at_zt; // pkt_sum wird für die Note 5 neu definiert
            pkt_percent = sum_at_zt / sum_result * 100; // pkt_percent wird für die Note 5 neu definiert
            grade = 5;
        }
        else if (pkt_percent >= 55 && pkt_percent < 67)
        {
            grade = 4;
        }
        else if (pkt_percent >= 67 && pkt_percent < 78)
        {
            grade = 3;
        }
        else if (pkt_percent >= 78 && pkt_percent < 89)
        {
            grade = 2;
        }
        else if (pkt_percent >= 89)
        {
            grade = 1;
        }
        printf("\nGesamtpunkte absolut: %.2f", pkt_sum);
        printf("\nGesamtpunkte %%: %.2f %%", pkt_percent);
        printf("\nNote: %d", grade);
    }
    return 0;
}