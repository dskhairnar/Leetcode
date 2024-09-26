class MyCalendar {
public:
    std::map<int, int> bookings; // Store intervals (start, end)
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto nextBooking = bookings.lower_bound(start);
        if (nextBooking != bookings.end() && nextBooking->first < end) {
            // Check if next booking starts before the current one ends
            return false;
        }
        if (nextBooking != bookings.begin() && std::prev(nextBooking)->second > start) {
            // Check if the previous booking ends after the current one starts
            return false;
        }
        bookings[start] = end; // No conflict, insert booking
        return true;
    }
};
