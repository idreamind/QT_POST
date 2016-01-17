/**
 * Created by dreamind on 16.01.2016.
 */
var express = require('express'),
    app     = express();

var bodyParser = require('body-parser');
app.use( bodyParser.json() );        // to support JSON-encoded bodies
app.use( bodyParser.urlencoded({     // to support URL-encoded bodies
    extended: true
}));

app.use(function (req, res) {
    switch (req.path) {
        case '/':
            res.send('Hello World!');
            break;
        case '/navigation':
            writeNavigation(req, res);
            break;
        default:
            res.send('Undefined');
            break;
    }
});

var listener = app.listen(3000, function () {
    console.log(' Server Run at ' + (new Date()).toDateString() + ' on port ' + listener.address().port);
});

function writeNavigation(req, res) {
    var lat = req.body.lat,
        lon = req.body.lon,
        alt = req.body.alt,
        time = req.body.time;

    var str = 'Lat:  ' + lat + '\n' + 'Lon:  ' + lon + '\n' + 'Alt:  ' + alt + '\n' + 'Time: ' + time + '\n';
    res.send(str);
    console.log(req.body);
    console.log(str);
}