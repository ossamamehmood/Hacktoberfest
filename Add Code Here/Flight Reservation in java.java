import java.time.LocalDateTime;
import java.util.*;

class Main {

    public static void main(String[] args) {
        // Create a flight reservation system
        FlightReservationSystem reservationSystem = new FlightReservationSystem();

        // Add some flights to the system
        Flight flight1 = new Flight("A123", "NAG", "DEL", LocalDateTime.of(2023, 10, 15, 10, 00),
                LocalDateTime.of(2023, 10, 15, 14, 00), "Indigo Airlines",
                new HashMap<>(Map.of("Economy", 100, "Business", 20)));
        reservationSystem.addFlight(flight1);

        Flight flight2 = new Flight("P456", "PNQ", "HYD", LocalDateTime.of(2023, 10, 20, 12, 00),
                LocalDateTime.of(2023, 10, 20, 16, 00), "Vistara Airlines",
                new HashMap<>(Map.of("Economy", 50, "Business", 10)));
        reservationSystem.addFlight(flight2);

        // Create a Scanner for user input
        Scanner scanner = new Scanner(System.in);

        // Display a menu to the user
        while (true) {
            System.out.println("\nFlight Reservation System Menu:");
            System.out.println("1. Search for Flights");
            System.out.println("2. Make a Reservation");
            System.out.println("3. Exit");
            System.out.print("Enter your choice (1/2/3): ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    // Search for flights
                    System.out.print("Enter departure airport code: ");
                    String departureAirport = scanner.nextLine();
                    System.out.print("Enter arrival airport code: ");
                    String arrivalAirport = scanner.nextLine();
                    System.out.print("Enter departure date (YYYY-MM-DD): ");
                    String departureDate = scanner.nextLine();
                    System.out.print("Enter number of passengers: ");
                    int numPassengers = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character
                    System.out.print("Enter travel class (Economy/Business): ");
                    String travelClass = scanner.nextLine();

                    // Search for flights based on user input
                    List<Flight> flights = reservationSystem.searchFlights(
                            departureAirport, arrivalAirport, departureDate,
                            null, numPassengers, travelClass);

                    // Display the search results
                    System.out.println();
                    System.out.println();
                    if (flights.isEmpty()) {
                        System.out.println("No flights matching the criteria were found.");
                    } else {
                        System.out.println("Found flights:");
                        for (Flight flight : flights) {
                            System.out.println(flight);
                        }
                    }
                    break;

                case 2:
                    // Make a reservation
                    System.out.print("Enter flight ID for reservation: ");
                    String flightId = scanner.nextLine();
                    System.out.print("Enter number of passengers: ");
                    numPassengers = scanner.nextInt();
                    scanner.nextLine();
                    // Check if the flight exists
                    Flight selectedFlight = reservationSystem.findFlightById(flightId);
                    if (selectedFlight == null) {
                        System.out.println("Flight not found.");
                    } else {
                        // Collect passenger information
                        List<Passenger> passengers = new ArrayList<>();
                        for (int i = 1; i <= numPassengers; i++) {
                            System.out.println("Passenger " + i + " details:");
                            System.out.print("Name: ");
                            String name = scanner.nextLine();
                            System.out.print("Email: ");
                            String email = scanner.nextLine();
                            System.out.print("Phone: ");
                            String phone = scanner.nextLine();
                            passengers.add(new Passenger(name, email, phone));
                        }

                        // Collect payment information
                        System.out.print("Enter credit card number: ");
                        String creditCardNumber = scanner.nextLine();
                        System.out.print("Enter expiration date (MM/YY): ");
                        String expirationDate = scanner.nextLine();

                        // Make the reservation
                        Reservation reservation = reservationSystem.makeReservation(
                                flightId, passengers, new PaymentInfo(creditCardNumber, expirationDate));

                        // Display the reservation details
                        System.out.println();
                        System.out.println();
                        System.out.println("Reservation created:");
                        System.out.println(reservation);
                    }
                    break;

                case 3:
                    // Exit the program
                    System.out.println("Exiting Flight Reservation System.");
                    scanner.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        }
    }
}

/**
 * a flight reservation system that allows users to search for
 * flights and make reservations.
 */
class FlightReservationSystem {

    private List<Flight> availableFlights;
    private List<Reservation> reservations;

    FlightReservationSystem() {
        availableFlights = new ArrayList<>();
        reservations = new ArrayList<>();
    }

    void addFlight(Flight flight) {
        availableFlights.add(flight);
    }

    /**
     * Searches for available flights based on the specified criteria.
     *
     * @param origin        The departure airport code.
     * @param destination   The arrival airport code.
     * @param departureDate The date of departure (YYYY-MM-DD).
     * @param returnDate    The date of return (YYYY-MM-DD, optional).
     * @param passengers    The number of passengers (adults, children, infants).
     * @param travelClass   The class of service (e.g., Economy, Business).
     * @return A list of available flight options.
     */
    List<Flight> searchFlights(String origin, String destination, String departureDate,
            String returnDate, int passengers, String travelClass) {
        // Implement flight search logic here
        // Return a list of Flight objects matching the criteria
        List<Flight> matchingFlights = new ArrayList<>();

        for (Flight flight : availableFlights) {
            if (flight.getDepartureAirportCode().equals(origin) &&
                    flight.getArrivalAirportCode().equals(destination) &&
                    flight.getAvailableSeatsByClass().containsKey(travelClass) &&
                    flight.getAvailableSeatsByClass().get(travelClass) >= passengers) {
                matchingFlights.add(flight);
            }
        }

        return matchingFlights;
    }

    /**
     * Makes a flight reservation for the specified flight and passengers.
     *
     * @param flightId    The unique identifier for the selected flight.
     * @param passengers  The list of passenger details.
     * @param paymentInfo The payment information (credit card details).
     * @return A reservation confirmation.
     */
    Reservation makeReservation(String flightId, List<Passenger> passengers, PaymentInfo paymentInfo) {
        // Implement reservation logic here
        // Return a reservation confirmation
        Flight selectedFlight = findFlightById(flightId);

        if (selectedFlight != null) {
            // Check if there are enough available seats
            int totalPassengers = passengers.size();
            int availableSeats = selectedFlight.getAvailableSeatsByClass().get("Economy"); // Assuming Economy class
            if (availableSeats >= totalPassengers) {
                String reservationId = generateUniqueReservationId();
                Reservation reservation = new Reservation(reservationId, selectedFlight, passengers, paymentInfo);
                reservations.add(reservation);
                // Update available seats
                selectedFlight.getAvailableSeatsByClass().put("Economy", availableSeats - totalPassengers);
                return reservation;
            } else {
                System.out.println("Not enough available seats for the selected flight.");
            }
        } else {
            System.out.println("Flight not found.");
        }

        return null;
    }

    /**
     * Finds a flight by its unique identifier.
     *
     * @param flightId The unique identifier for the flight.
     * @return The matching Flight object, or null if not found.
     */
    Flight findFlightById(String flightId) {
        for (Flight flight : availableFlights) {
            if (flight.getFlightId().equals(flightId)) {
                return flight;
            }
        }
        return null; // Flight not found
    }

    /**
     * Generates a unique reservation identifier (e.g., using UUID).
     *
     * @return A unique reservation identifier.
     */
    private String generateUniqueReservationId() {
        // You can use java.util.UUID.randomUUID() to generate a unique ID
        return UUID.randomUUID().toString();
    }

}

/**
 * Represents a flight available for booking.
 */
class Flight {

    private String flightId;
    private String departureAirportCode;
    private String arrivalAirportCode;
    private LocalDateTime departureDateTime;
    private LocalDateTime arrivalDateTime;
    private String airline;
    private Map<String, Integer> availableSeatsByClass;

    Flight(String flightId, String departureAirportCode, String arrivalAirportCode,
            LocalDateTime departureDateTime, LocalDateTime arrivalDateTime, String airline,
            Map<String, Integer> availableSeatsByClass) {
        this.flightId = flightId;
        this.departureAirportCode = departureAirportCode;
        this.arrivalAirportCode = arrivalAirportCode;
        this.departureDateTime = departureDateTime;
        this.arrivalDateTime = arrivalDateTime;
        this.airline = airline;
        this.availableSeatsByClass = availableSeatsByClass;
    }

    /**
     * Gets the unique identifier for the flight.
     *
     * @return The flight's unique identifier.
     */
    String getFlightId() {
        return flightId;
    }

    /**
     * Gets the departure airport code for the flight.
     *
     * @return The departure airport code.
     */
    String getDepartureAirportCode() {
        return departureAirportCode;
    }

    /**
     * Gets the arrival airport code for the flight.
     *
     * @return The arrival airport code.
     */
    String getArrivalAirportCode() {
        return arrivalAirportCode;
    }

    /**
     * Gets the departure date and time for the flight.
     *
     * @return The departure date and time.
     */
    LocalDateTime getDepartureDateTime() {
        return departureDateTime;
    }

    /**
     * Gets the arrival date and time for the flight.
     *
     * @return The arrival date and time.
     */
    LocalDateTime getArrivalDateTime() {
        return arrivalDateTime;
    }

    /**
     * Gets the airline name for the flight.
     *
     * @return The airline name.
     */
    String getAirline() {
        return airline;
    }

    /**
     * Gets the flight's available seats in different travel classes.
     *
     * @return A map where keys are travel class names (e.g., "Economy") and values
     *         are available seat counts.
     */
    Map<String, Integer> getAvailableSeatsByClass() {
        return availableSeatsByClass;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(flightId).append(" - ").append(airline).append(" - ").append(departureAirportCode)
                .append(" - ").append(arrivalAirportCode).append(" - ").append(departureDateTime)
                .append(" - ").append(arrivalDateTime).append("\n");

        for (Map.Entry<String, Integer> entry : availableSeatsByClass.entrySet()) {
            sb.append(entry.getKey()).append(": ").append(entry.getValue()).append(" seats available\n");
        }

        return sb.toString();
    }
    // Other flight-related properties and methods
}

/**
 * Represents a passenger with personal information.
 */
class Passenger {

    private String name;
    private String email;
    private String phone;

    Passenger(String name, String email, String phone) {
        this.name = name;
        this.email = email;
        this.phone = phone;
    }

    /**
     * Gets the name of the passenger.
     *
     * @return The passenger's name.
     */
    String getName() {
        // Implement getter method
        return name;
    }

    /**
     * Sets the name of the passenger.
     *
     * @param name The passenger's name.
     */
    void setName(String name) {
        this.name = name;
    }

    /**
     * Gets the email address of the passenger.
     *
     * @return The passenger's email address.
     */
    String getEmail() {
        return email;
    }

    /**
     * Sets the email address of the passenger.
     *
     * @param email The passenger's email address.
     */
    void setEmail(String email) {
        this.email = email;
    }

    /**
     * Gets the phone number of the passenger.
     *
     * @return The passenger's phone number.
     */
    String getPhone() {
        return phone;
    }

    /**
     * Sets the phone number of the passenger.
     *
     * @param phone The passenger's phone number.
     */
    void setPhone(String phone) {
        this.phone = phone;
    }
    // Other passenger-related properties and methods
}

/**
 * Represents payment information for a reservation.
 */
class PaymentInfo {

    private String creditCardNumber;
    private String expirationDate;

    PaymentInfo(String creditCardNumber, String expirationDate) {
        this.creditCardNumber = creditCardNumber;
        this.expirationDate = expirationDate;
    }

    /**
     * Gets the credit card number used for payment.
     *
     * @return The credit card number.
     */
    String getCreditCardNumber() {
        return creditCardNumber;
    }

    /**
     * Sets the credit card number used for payment.
     *
     * @param creditCardNumber The credit card number.
     */
    void setCreditCardNumber(String creditCardNumber) {
        this.creditCardNumber = creditCardNumber;
    }

    /**
     * Gets the credit card expiration date.
     *
     * @return The credit card expiration date.
     */
    String getExpirationDate() {
        return expirationDate;
    }

    /**
     * Sets the credit card expiration date.
     *
     * @param expirationDate The credit card expiration date.
     */
    void setExpirationDate(String expirationDate) {
        this.expirationDate = expirationDate;
    }

    // Other payment-related properties and methods
}

/**
 * Represents a flight reservation confirmation.
 */
class Reservation {

    private String reservationId;
    private Flight flight;
    private List<Passenger> passengers;
    private PaymentInfo paymentInfo;

    Reservation(String reservationId, Flight flight, List<Passenger> passengers, PaymentInfo paymentInfo) {
        this.reservationId = reservationId;
        this.flight = flight;
        this.passengers = passengers;
        this.paymentInfo = paymentInfo;
    }

    /**
     * Gets the unique identifier for the reservation.
     *
     * @return The reservation's unique identifier.
     */
    String getReservationId() {
        return reservationId;
    }

    /**
     * Gets the flight that is being reserved.
     *
     * @return The flight that is being reserved.
     */
    Flight getFlight() {
        return flight;
    }

    /**
     * Gets the passengers on the reservation.
     *
     * @return The passengers on the reservation.
     */
    List<Passenger> getPassengers() {
        return passengers;
    }

    /**
     * Gets the payment information for the reservation.
     *
     * @return The payment information for the reservation.
     */
    PaymentInfo getPaymentInfo() {
        return paymentInfo;
    }

    @Override
    public String toString() {
        StringBuilder passengerNames = new StringBuilder();
        for (Passenger passenger : passengers) {
            passengerNames.append(passenger.getName()).append("\n");
        }

        return String.format("Reservation ID: %s\nFlight ID: %s\nPassengers:\n%s",
                reservationId, flight.getFlightId(), passengerNames.toString());
    }
    // Other reservation-related properties and methods
}
