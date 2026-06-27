#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_SEATS 50
#define TICKET_PRICE 12.50
typedef struct {
    int bookingId;
    char customerName[50];
    int seatNumber;
} Ticket;
int seats[TOTAL_SEATS + 1] = {0};
Ticket bookings[TOTAL_SEATS];
int bookingCount = 0;
int nextBookingId = 1001;
void displayMenu();
void viewShows();
void checkAvailability();
void bookTicket();
void viewBookings();
int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }
        switch (choice) {
            case 1:
                viewShows();
                break;
            case 2:
                checkAvailability();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                printf("\nThank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=========================================\n");
    printf("       TICKET BOOKING SYSTEM IN C        \n");
    printf("=========================================\n");
    printf("1. View Current Shows\n");
    printf("2. Check Seat Availability Map\n");
    printf("3. Book a Ticket\n");
    printf("4. View All Booked Tickets\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
}
void viewShows() {
    printf("\n--- Currently Playing ---\n");
    printf("Movie: Sci-Fi Odyssey (3D)\n");
    printf("Time:  07:30 PM\n");
    printf("Price: $%.2f per ticket\n", TICKET_PRICE);
}
void checkAvailability() {
    printf("\n--- Seat Availability Map ---\n");
    printf("[A]: Available   [B]: Booked\n\n");
    for (int i = 1; i <= TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("%02d:[A]  ", i);
        } else {
            printf("%02d:[B]  ", i);
        }
            if (i % 10 == 0) {
            printf("\n");
        }
    }
}
void bookTicket() {
    if (bookingCount >= TOTAL_SEATS) {
        printf("\nSorry, the show is fully booked!\n");
        return;
    }
    Ticket newTicket;
    newTicket.bookingId = nextBookingId;
    printf("\nEnter Passenger/Customer Name: ");
    getchar(); // Clear the input buffer trailing newline
    fgets(newTicket.customerName, sizeof(newTicket.customerName), stdin);
    newTicket.customerName[strcspn(newTicket.customerName, "\n")] = '\0'; 
    checkAvailability();
    printf("\nEnter preferred seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &newTicket.seatNumber);
    if (newTicket.seatNumber < 1 || newTicket.seatNumber > TOTAL_SEATS) {
        printf("Error: Invalid seat number choice.\n");
        return;
    }
    if (seats[newTicket.seatNumber] == 1) {
        printf("Error: Seat %d is already taken.\n", newTicket.seatNumber);
        return;
    }
    seats[newTicket.seatNumber] = 1;
    bookings[bookingCount] = newTicket;
    bookingCount++;
    nextBookingId++;
    printf("\nProcessing... Booking Successful!\n");
    printf("-----------------------------------------\n");
    printf("             TICKET RECEIPT              \n");
    printf("-----------------------------------------\n");
    printf("Booking ID : %d\n", newTicket.bookingId);
    printf("Name       : %s\n", newTicket.customerName);
    printf("Seat No    : %d\n", newTicket.seatNumber);
    printf("Total Paid : $%.2f\n", TICKET_PRICE);
    printf("-----------------------------------------\n");
}
void viewBookings() {
    if (bookingCount == 0) {
        printf("\nNo tickets have been booked yet.\n");
        return;
    }
    printf("\n=========================================\n");
    printf("ID\t\tSeat\t\tPassenger Name\n");
    printf("=========================================\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("%d\t\t%d\t\t%s\n", bookings[i].bookingId, bookings[i].seatNumber, bookings[i].customerName);
    }
}
