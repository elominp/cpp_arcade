//
// Created by pirou_g on 28/03/16.
//

#include "AEvents.hh"

AEvents::AEvents(AEvents const &event):
        _event(event._event) {}

AEvents::AEvents(Event event):
        _event(event) {}

AEvents &AEvents::operator=(AEvents const &events) {
    _event = events._event;
    return *this;
}

AEvents &AEvents::operator=(Event event) {
    _event.push_back(event);
    return *this;
}