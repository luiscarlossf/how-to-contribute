from flask import render_template
# Import to use redirect and url_for methods
from flask import url_for, redirect
# Imported a function to render templates

from app import app

@app.route('/')
@app.route('/index')
def index():
	user = {'nickname': 'Mitesh'}
	posts = [
		{
			'author': {'nickname': 'Mitesh'},
			'body': 'Beautiful Day in Hyderabad!'
		},
		{
			'author': {'nickname': 'Mitesh'},
			'body': 'Andhadhun Movie was so cool.'
		}
	]
	return render_template('index.html',title='Home',user=user,posts=posts)

@app.route('/about')
def about():
	return render_template('about.html')

@app.route('/admin')
def hello_admin():
	return "Hello Admin!"

@app.route('/guest/<guest>')
def hello_guest(guest):
	return "Hello Guest %s!" % guest

@app.route('/user/<name>')
def hello_user(name):
	if name == 'admin':
		return redirect(url_for('hello_admin'))
	else:
		return redirect(url_for('hello_guest',guest = name))

# Confused about Redirect? Will be explained soon. :-)