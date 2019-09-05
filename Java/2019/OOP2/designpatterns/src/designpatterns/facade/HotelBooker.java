package designpatterns.facade;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class HotelBooker {

    public List<Hotel> getHotelNamesFor(Date from, Date to) {        
        List<Hotel> hotels = new ArrayList<>();
        //returns hotels available in the particular date range
        return hotels;
    }
}
