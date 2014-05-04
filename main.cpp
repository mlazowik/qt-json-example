#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class Gun {
    public:
        enum GunType {
            Handgun, Machine, Training
        };

        Gun();
        Gun(QString name, int range, GunType type);

        QString getName() const;
        void setName(const QString &name);

        int getRange() const;
        void setRange(int range);

        GunType getType() const;
        void setType(GunType type);

        void read(const QJsonObject &json);
        void write(QJsonObject &json) const;

    private:
        QString mName;
        int mRange;
        GunType mType;
};

QString Gun::getName() const {
    return mName;
}

void Gun::setName(const QString &name) {
    mName = name;
}

int Gun::getRange() const {
    return mRange;
}

void Gun::setRange(int range) {
    mRange = range;
}

Gun::GunType Gun::getType() const {
    return mType;
}

void Gun::setType(GunType type) {
    mType = type;
}

void Gun::read(const QJsonObject &json) {
    mName = json["name"].toString();
    mRange = json["level"].toDouble();
    mType = GunType(qRound(json["type"].toDouble()));
}

void Gun::write(QJsonObject &json) const {
    json["name"] = mName;
    json["range"] = mRange;
    json["type"] = mType;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "This appears";

    return a.exec();
}
