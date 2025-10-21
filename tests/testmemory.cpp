#include <QtTest>
#include "memory.h"
#include "support/cout_capture.h"

class TestMemory : public QObject {
    Q_OBJECT
private slots:
    void secuencia_basica() {
        MemoryManager m(4, 8);
        std::vector<int> refs = {1,2,3,2,4,1,5,2,3,4};

        {   CoutCapture cap;
            m.simulateReferences(refs, MemoryManager::Policy::FIFO);
            QVERIFY(cap.str().find("policy FIFO") != std::string::npos);
        }
        {   CoutCapture cap;
            m.simulateReferences(refs, MemoryManager::Policy::LRU);
            QVERIFY(cap.str().find("policy LRU") != std::string::npos);
        }
    }
};
QTEST_MAIN(TestMemory)
#include "testmemory.moc"
