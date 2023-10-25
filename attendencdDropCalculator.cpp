#include <stdio.h>
#include <time.h>

int main() {
    int day1, month1, year1, day2, month2, year2;
    printf("Enter  first date of your leave (dd mm yyyy) with space : ");
    scanf("%d %d %d", &day1, &month1, &year1);

    printf("Enter last date of your leave (dd mm yyyy) with space : ");
    scanf("%d %d %d", &day2, &month2, &year2);

    struct tm start_date = {0};
    struct tm end_date = {0};

    start_date.tm_year = year1 - 1900;
    start_date.tm_mon = month1 - 1;
    start_date.tm_mday = day1;

    end_date.tm_year = year2 - 1900;
    end_date.tm_mon = month2 - 1;
    end_date.tm_mday = day2;

    time_t start_time = mktime(&start_date);
    time_t end_time = mktime(&end_date);

    if (start_time == -1 || end_time == -1) {
        printf("Invalid.\n");
        return 1;
    }

    double seconds = difftime(end_time, start_time);
    double days = seconds / 86400; // 86400 seconds in a day

    int lectures[(int)days + 1];

    for (int i = 0; i <= days; i++) {
        struct tm current_date = *localtime(&start_time);
        current_date.tm_mday += i;
        time_t current_time = mktime(&current_date);
        printf("Enter the number of lectures for %d/%d/%d: ", current_date.tm_mday, current_date.tm_mon + 1, current_date.tm_year + 1900);
        scanf("%d", &lectures[i]);
    }

    int totalAttended = 0;
    for (int i = 0; i <= days; i++) {
        struct tm current_date = *localtime(&start_time);
        current_date.tm_mday += i;
        time_t current_time = mktime(&current_date);

        int lecturesAttended;
        printf("How many lectures will you attend on %d/%d/%d: ", current_date.tm_mday, current_date.tm_mon + 1, current_date.tm_year + 1900);
        scanf("%d", &lecturesAttended);
        totalAttended += lecturesAttended;
    }

    // Calculate the total number of lectures attended during leave period
    int totalLecturesLeave = 0;
    for (int i = 0; i <= days; i++) {
        totalLecturesLeave += lectures[i];
    }

    // Ask the user for total lectures that have happened in the past
    int totalLecturesPast;
    printf("Enter the total lectures that have happened in the past: ");
    scanf("%d", &totalLecturesPast);

    // Ask the user for total lectures attended in the past
    int totalAttendedPast;
    printf("Enter the total lectures attended in the past: ");
    scanf("%d", &totalAttendedPast);

    // Calculate total lectures and attendance by adding past and future
    int totalLecturesTotal = totalLecturesPast + totalLecturesLeave;
    int totalAttendedTotal = totalAttendedPast + totalAttended;

    // Calculate the total attendance percentage
    float attendancePercentage = ((float)totalAttendedTotal / totalLecturesTotal) * 100;

    // Calculate past attendance percentage
    float pastAttendancePercentage = ((float)totalAttendedPast / totalLecturesPast) * 100;

    // Calculate the drop in percentage
    float dropPercentage = pastAttendancePercentage - attendancePercentage;

    // Ask the user if they want to add more lectures
    char moreLectures;
    printf("Do you want to add more lectures (y/n)? ");
    scanf(" %c", &moreLectures);

    if (moreLectures == 'y' || moreLectures == 'Y') {
        int additionalTotalLectures;
        printf("Enter the total number of additional lectures: ");
        scanf("%d", &additionalTotalLectures);

        int additionalLecturesAttended;
        printf("Enter the number of additional lectures you will attend: ");
        scanf("%d", &additionalLecturesAttended);

        // Update total lectures and attendance by adding additional data
        totalLecturesTotal += additionalTotalLectures;
        totalAttendedTotal += additionalLecturesAttended;

        // Recalculate the attendance percentage
        attendancePercentage = ((float)totalAttendedTotal / totalLecturesTotal) * 100;
    }

    printf("Total lectures attended during leave period: %d\n", totalLecturesLeave);
    printf("Total lectures attended in the past: %d\n", totalAttendedPast);
    printf("Total lectures attended in total: %d\n", totalAttendedTotal);
    printf("Total lectures in the past: %d\n", totalLecturesPast);
    printf("Total lectures in total: %d\n", totalLecturesTotal);
    printf("Attendance Percentage: %.2f%%\n", attendancePercentage);
    printf("Past Attendance Percentage: %.2f%%\n", pastAttendancePercentage);
    printf("Drop in Percentage: %.2f%%\n", dropPercentage);

    return 0;
}
