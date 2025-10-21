#include <QtTest>
#include "tlb.h"

class TestTLB : public QObject {
    Q_OBJECT
private slots:
    void fifo_basico() {
        TLB tlb(2);
        QCOMPARE(tlb.lookup(1), -1);
        tlb.insert(1,10);
        QCOMPARE(tlb.lookup(1), 10);
        tlb.insert(2,20);
        QCOMPARE(tlb.lookup(2), 20);
        tlb.insert(3,30); // expulsa 1
        QCOMPARE(tlb.lookup(1), -1);
        QCOMPARE(tlb.lookup(3), 30);
    }
};
QTEST_MAIN(TestTLB)
#include "testtlb.moc"
