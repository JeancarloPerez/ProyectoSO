#include <QtTest>
#include "producer_consumer.h"
#include "support/cout_capture.h"

class TestPC : public QObject {
    Q_OBJECT
private slots:
    void produce_y_consume_en_ventana_corta() {
        ProducerConsumer pc;
        CoutCapture cap;
        pc.start();
        bool vioAlgo = false;
        for (int i=0; i<10; ++i) {
            QTest::qWait(100);
            auto out = cap.str();
            if (out.find("Produced:") != std::string::npos ||
                out.find("Consumed:") != std::string::npos) {
                vioAlgo = true; break;
            }
        }
        QVERIFY2(vioAlgo, "No se observaron prints de producción/consumo");
        pc.stop();
    }
};
QTEST_MAIN(TestPC)
#include "testpc.moc"
