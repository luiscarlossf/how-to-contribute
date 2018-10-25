# Views are handlers that responds to requests from browsers and clients

# Handlers are written as Python Functions. 

# Each View Function is mapped to one or more request URLs.

from app import app

# Map 2 Routes to the same Function. Can map a single route too.

@app.route('/')
@app.route('/index')
def index():
	return "Hello World!"

# Simple returns a string to the client :-)