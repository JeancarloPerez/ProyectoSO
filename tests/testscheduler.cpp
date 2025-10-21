#include <QtTest>
#include "scheduler.h"
#include "support/cout_capture.h"

class TestScheduler : public QObject {
    Q_OBJECT
private slots:
    void fcfs_basico() {
        Scheduler s;
        s.addProcess({2,1,3});
        s.addProcess({1,0,5});
        s.addProcess({3,6,2});
        CoutCapture cap;
        s.runFCFS();
        const auto out = cap.str();
        QVERIFY(out.find("PID 2") != std::string::npos);
        QVERIFY(out.find("PID 1") != std::string::npos);
        QVERIFY(out.find("PID 3") != std::string::npos);
    }
};
QTEST_MAIN(TestScheduler)
#include "testscheduler.moc"
