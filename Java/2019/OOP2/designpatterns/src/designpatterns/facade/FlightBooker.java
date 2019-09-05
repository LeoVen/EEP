package designpatterns.facade;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class FlightBooker {

    public List<Flight> getFlightsFor(Date from, Date to) {
        List<Flight> flights = new ArrayList<>();
        //returns flights available in the particular date range
        return flights;
    }
}
