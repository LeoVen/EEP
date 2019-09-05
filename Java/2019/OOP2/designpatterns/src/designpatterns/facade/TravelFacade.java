package designpatterns.facade;

import java.util.Date;
import java.util.List;

public class TravelFacade {

    private HotelBooker hotelBooker;
    private FlightBooker flightBooker;

    public void getFlightsAndHotels(Date from, Date to) {
        List<Flight> flights = flightBooker.getFlightsFor(from, to);
        List<Hotel> hotels = hotelBooker.getHotelNamesFor(from, to);
        //process the reservations
    }
}
