#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include <QTimer>
#include <cmath>
#include <QDebug>

/* Purpose of class: Signal Generator QObject to generate and emit the signal of a sine wave at a certain frequency
 *
 * Data Members:
 * - QTimer* timer: A QTimer object to call and generate a signal based on the sample rate
 * - int sampleRateHz:
 * - double angle:
 *
 * Class functions:
 *
 */

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    SignalGenerator(QObject *parent = nullptr);

    // Will probably need this to get frequency for analysis
    double getDeltaAmplitude();
    double getThetaAmplitude();
    double getAlphaAmplitude();
    double getBetaAmplitude();
    
    double getDeltaFrequency();
    double getThetaFrequency();
    double getAlphaFrequency();
    double getBetaFrequency();

    // Setters for amplitudes
    void setDeltaAmplitude(double);
    void setThetaAmplitude(double);
    void setAlphaAmplitude(double);
    void setBetaAmplitude(double);

    // Setters for frequencies
    void setDeltaFrequency(double);
    void setThetaFrequency(double);
    void setAlphaFrequency(double);
    void setBetaFrequency(double);


    // Start and stop generating EEG signal
    void start();
    void stop();

signals:
    void signalGenerated(double);

public slots:
    void generateEEGSignal();

private:
    // Timer to generate signal based on sample rate
    QTimer* timer;

    double currTime;
    int sampleRateHz;
    
    // Amplitude for each band
    double deltaAmp;
    double thetaAmp;
    double alphaAmp;
    double betaAmp;

    // Frequencies for each band
    double deltaFreq;
    double thetaFreq;
    double alphaFreq;
    double betaFreq;
};
#endif // SIGNALGENERATOR_H