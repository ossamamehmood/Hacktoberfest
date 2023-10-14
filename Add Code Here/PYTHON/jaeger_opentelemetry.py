import random
import logging
from fastapi import FastAPI
from jaeger_client import Config
from opentracing_instrumentation.request_context import get_current_span, span_in_context

app = FastAPI()

def init_tracer(service):
    logging.getLogger('').handlers = []
    logging.basicConfig(format='%(message)s', level=logging.DEBUG)
    config = Config(
        config={
            'sampler': {
                'type': 'const',
                'param': 1,
            },
            'logging': True,
        },
        service_name=service
    )
    return config.initialize_tracer()

tracer = init_tracer('booking_movie')

def booking_mgr(movie):
    with tracer.start_span('booking') as span:
        span.set_tag('Movie', movie)
        with span_in_context(span):
            cinema_details = check_cinema(movie)
            showtime_details = check_showtime(cinema_details)
            book_show(showtime_details)

def check_cinema(movie):
    with tracer.start_span('CheckCinema', child_of=get_current_span()) as span:
        with span_in_context(span):
            cinema_details = f"{movie} Details"
            flags = ['false', 'true', 'false']
            random_flag = random.choice(flags)
            span.set_tag('error', random_flag)
            span.log_kv({'event': 'CheckCinema', 'value': cinema_details})
            return cinema_details

def check_showtime(cinema_details):
    with tracer.start_span('CheckShowtime', child_of=get_current_span()) as span:
        with span_in_context(span):
            showtime_details = f"Showtime {cinema_details} Details"
            flags = ['false', 'true', 'false']
            random_flag = random.choice(flags)
            span.set_tag('error', random_flag)
            span.log_kv({'event': 'CheckShowtime', 'value': showtime_details})
            return showtime_details

def book_show(showtime_details):
    with tracer.start_span('BookShow', child_of=get_current_span()) as span:
        with span_in_context(span):
            ticket_details = "Ticket Details"
            flags = ['false', 'true', 'false']
            random_flag = random.choice(flags)
            span.set_tag('error', random_flag)
            span.log_kv({'event': 'BookShow', 'value': ticket_details})
            print(showtime_details)
            print(ticket_details)

@app.get("/book_movie/{movie}")
async def book_movie(movie: str):
    booking_mgr(movie)
    return {"message": f"Booking for movie {movie} completed successfully."}

# Ensure to close the tracer when done
@app.on_event("shutdown")
def shutdown_tracer():
    tracer.close()

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
