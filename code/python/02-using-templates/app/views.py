from flask import render_template

# Imported a function to render templates

from app import app

@app.route('/')
@app.route('/index')
def index():
	user = {'nickname': 'Mitesh'}
	return render_template('index.html',title='Home',user=user)
	# return render_template('index.html',user=user)

# render_template() takes a template file name and a variable list of template file arguments.
# Returns the rendered template with all the arguments replaced
# By default looks for the template files in app/templates/ directory

# @app.route('/')
# @app.route('/index')
# def index():
# 	user = {'nickname': 'Mitesh'}
# 	posts = [
# 		{
# 			'author': {'nickname': 'Mitesh'},
# 			'body': 'Beautiful Day in Hyderabad!'
# 		},
# 		{
# 			'author': {'nickname': 'Mitesh'},
# 			'body': 'Andhadhun Movie was so cool.'
# 		}
# 	]
# 	return render_template('index.html',title='Home',user=user,posts=posts)