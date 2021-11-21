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

String labels[65];
int BandCutoffTable[65];
//int loopcounter=0;
//double bndcounter[64];
static int BandCutoffTable8[8] =
{
  100, 250, 500, 1000, 2000, 4000, 8000, 16000
};

String labels8[] =
{
  "100", "250", "500", "1K", "2K", "4K", "8K", "16K"
};

static int BandCutoffTable16[16] =
{
  30, 50, 100, 150, 250, 400, 650, 1000, 1600, 2500, 4000, 6000, 12000, 14000, 16000, 17000
};

String labels16[] =
{
  "30", "50", "100", "150", "250", "400", "650", "1K",
  "1K6", "2K5" , "4K", "6K", "12K", "14K", "16K", "17K"
};

static int BandCutoffTable24[24] =
{
  40, 80, 150, 220, 270, 320, 380, 440, 540, 630,  800, 1000, 1250, 1600, 2000, 2500, 3150,
  3800, 4200, 4800, 5400, 6200, 7400, 12500
};

String labels24[] =
{
  "40", "80", "150", "220", "270", "320", "380", "440",
  "540", "630", " 800", "1000", "1250", "1600", "2000", "2500",
  "3150", "3800", "4200", "4800", "5400", "6200", "7400", "12500"
};

static int BandCutoffTable32[32] =
{
  45, 90, 130, 180, 220, 260, 310, 350,
  390, 440, 480, 525, 650, 825, 1000, 1300,
  1600, 2050, 2500, 3000, 4000, 5125, 6250, 9125,
  12000, 13000, 14000, 15000, 16000, 16500, 17000, 17500
};

String labels32[] =
{
  "45", "90", "130", "180", "220", "260", "310", "350",
  "390", "440", "480", "525", "650", "825", "1K", "1K3",
  "1K6", "2K05", "2K5", "3K", "4K", "5125", "6250", "9125",
  "12K", "13K", "14K", "15K", "16K", "16K5", "17K", "17K5"
};

static int BandCutoffTable64[64] =
{
  45, 90, 130, 180, 220, 260, 310, 350
  , 390, 440, 480, 525, 565, 610, 650, 690
  , 735, 780, 820, 875, 920, 950, 1000, 1050
  , 1080, 1120, 1170, 1210, 1250, 1300, 1340, 1380
  , 1430, 1470, 1510, 1560, 1616, 1767, 1932, 2113
  , 2310, 2526, 2762, 3019, 3301, 3610, 3947, 4315
  , 4718, 5159, 5640, 6167, 6743, 7372, 8061, 8813
  , 9636, 10536, 11520, 12595, 13771, 15057, 16463, 18000

};

String labels64[] =
{
  "45", "90", "130", "180", "220", "260", "310", "350",
  "390", "440", "480", "525", "565", "610", "650", "690",
  "735", "780", "820", "875", "920", "950", "1000", "1050",
  "1080", "1120", "1170", "1210", "1250", "1300", "1340", "1380",
  "1430", "1470", "1510", "1560", "1616", "1767", "1932", "2113",
  "2310", "2526", "2762", "3019", "3301", "3610", "3947", "4315",
  "4718", "5159", "5640", "6167", "6743", "7372", "8061", "8813",
  "9636", "10536", "11520", "12595", "13771", "15057", "16463", "18K"
};


void SetNumberofBands(int bandnumber) {
  switch (bandnumber)
  {
    case 8:
      for (int x = 0; x < bandnumber; x++)
      {
        BandCutoffTable[x] = BandCutoffTable8[x];
        labels[x] = labels8[x];
      }
      break;

    case 16:
      for (int x = 0; x < bandnumber; x++)
      {
        BandCutoffTable[x] = BandCutoffTable16[x];
        labels[x] = labels16[x];
      }
      break;

    case 24:
      for (int x = 0; x < bandnumber; x++)
      {
        BandCutoffTable[x] = BandCutoffTable24[x];
        labels[x] = labels24[x];
      }

      break;

    case 32:
      for (int x = 0; x < bandnumber; x++)
      {
        BandCutoffTable[x] = BandCutoffTable32[x];
        labels[x] = labels32[x];
      }

      break;
    case 64:
      for (int x = 0; x < bandnumber; x++)
      {
        BandCutoffTable[x] = BandCutoffTable64[x];
        labels[x] = labels64[x];
      }

      break;
  }

}
