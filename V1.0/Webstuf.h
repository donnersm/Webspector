 /********************************************************************************************************************************************************
 *                                                                                                                                                       *
 *  Project:         Webspector - WebServer based Spectrum Analyzer                                                                                      *
 *  Target Platform: ESP32                                                                                                                               *
 *                                                                                                                                                       * 
 *  Version: 1.0                                                                                                                                         *
 *  Hardware setup: See github                                                                                                                           *
 *                                                                                                                                                       *
 *                                                                                                                                                       * 
 *  Mark Donners                                                                                                                                         *
 *  The Electronic Engineer                                                                                                                              *
 *  Website:   www.theelectronicengineer.nl                                                                                                              *
 *  facebook:  https://www.facebook.com/TheelectronicEngineer                                                                                            *
 *  youtube:   https://www.youtube.com/channel/UCm5wy-2RoXGjG2F9wpDFF3w                                                                                  *
 *  github:    https://github.com/donnersm                                                                                                               *
 *                                                                                                                                                       *  
 ********************************************************************************************************************************************************/
 

#pragma once



// Serving a web page (from flash memory)
// formatted as a string literal!
char webpage[] PROGMEM = R"=====(
<html>
<!-- Adding a data chart using Chart.js -->
<head>
  <script src='https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js'></script>

</head>
<body onload="javascript:init()">
<style>

</style>
<h2>Analog Spectrum Analyzer</h2>
<div>
  <canvas id="chart" width="1200" height="800" style="background: url('http://www.judoles.nl/Projecten/Logo200.png');  background-repeat: no-repeat;background-position-x: center;;background-position-y: center;"></canvas>
</div>
<!-- Adding a websocket to the client (webpage) -->
<script>
  var webSocket, dataPlot;
  var maxDataPoints = 20;
  const maxValue = 1;//200000000;
  const maxLow = maxValue * 0.6;
  const maxMedium = maxValue * 0.3;
  const maxHigh = maxValue * 0.1;
const image = new Image();
image.src = 'https://www.chartjs.org/img/chartjs-logo.svg';

  function init() {
    webSocket = new WebSocket('ws://' + window.location.hostname + ':81/');
    dataPlot = new Chart(document.getElementById("chart"), {
      type: 'bar',
      data: {
        labels: [],        
        datasets: [{
          data: [],
          label: "Low",
          backgroundColor: "green",//"#D6E9C6"
          borderColor:"black",
          borderWidth: 3
        },
        {
          data: [],
          label: "Moderate",
          backgroundColor: "yellow", //"#FAEBCC"
          borderColor:"black",
          borderWidth: 3
        },
        {
          data: [],
          label: "High",
          backgroundColor: "red", //"#EBCCD1"
          borderColor:"black",
          borderWidth: 3
        },
        ]
      }, 
      options: {
          responsive: false,
          animation: false,
          scales: {
              xAxes: [{ stacked: true }],
              yAxes: [{
                  display: true,
                  stacked: true,
                  ticks: {
                    beginAtZero: true,
                    steps: 1000,
                    stepValue: 50,
                    max: maxValue
                  }
              }]
           }
       }
    });

    
    webSocket.onmessage = function(event) {
      var data = JSON.parse(event.data);
      dataPlot.data.labels = [];
      dataPlot.data.datasets[0].data = [];
      dataPlot.data.datasets[1].data = [];
      dataPlot.data.datasets[2].data = [];
      
      data.forEach(function(element) {
        dataPlot.data.labels.push(element.bin);
        var lowValue = Math.min(maxLow, element.value);
        dataPlot.data.datasets[0].data.push(lowValue);
        
        var mediumValue = Math.min(Math.max(0, element.value - lowValue), maxMedium);
        dataPlot.data.datasets[1].data.push(mediumValue);
        
        var highValue = Math.max(0, element.value - lowValue - mediumValue);
        dataPlot.data.datasets[2].data.push(highValue);

      });
      dataPlot.update();
    }
  }

</script>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td><a href="http://www.theelectronicengineer.nl" target="_blank"><h3 align="left">The Electronic Engineer   -   </h3></a></td>
    <td><a href="https://www.buymeacoffee.com/MarkDonners"  target="_blank"><h3 align="left">If you like, you can buy me a coffee to keep me up and running</h3></a></td>
  </tr>
</table>

</body>
</html>
)=====";
