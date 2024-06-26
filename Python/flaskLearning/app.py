from flask import Flask
from flask import render_template
app = Flask(__name__)


@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Egor'}
    posts = [
        {
            'author': {'username': 'John'},
            'body': 'Beautiful day in Portland!'
        },
        {
            'author': {'username': 'Susan'},
            'body': 'The Avengers movie was so cool!'
        },
        {
            'author': {'username': 'Ипполит'},
            'body': 'Какая гадость эта ваша заливная рыба!!'
        }
    ]
    return render_template('index.html', title='Home', user=user, posts=posts)
if __name__ == '__main__':
    app.run()
