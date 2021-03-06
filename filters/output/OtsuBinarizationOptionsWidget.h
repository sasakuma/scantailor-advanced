
#ifndef SCANTAILOR_OTSUBINARIZATIONOPTIONSWIDGET_H
#define SCANTAILOR_OTSUBINARIZATIONOPTIONSWIDGET_H

#include <QtCore>
#include <list>
#include "BinarizationOptionsWidget.h"
#include "ColorParams.h"
#include "Settings.h"
#include "intrusive_ptr.h"
#include "ui_OtsuBinarizationOptionsWidget.h"

namespace output {
class OtsuBinarizationOptionsWidget : public BinarizationOptionsWidget, private Ui::OtsuBinarizationOptionsWidget {
  Q_OBJECT
 public:
  explicit OtsuBinarizationOptionsWidget(intrusive_ptr<Settings> settings);

  ~OtsuBinarizationOptionsWidget() override = default;

  void updateUi(const PageId& m_pageId) override;

 private slots:

  void thresholdSliderReleased();

  void thresholdSliderValueChanged(int value);

  void setLighterThreshold();

  void setDarkerThreshold();

  void setNeutralThreshold();

  void sendStateChanged();

 private:
  void updateView();

  void setThresholdAdjustment(int value);

  void setupUiConnections();

  void removeUiConnections();

  intrusive_ptr<Settings> m_settings;
  PageId m_pageId;
  ColorParams m_colorParams;
  QTimer m_delayedStateChanger;
  int m_ignoreSliderChanges;

  std::list<QMetaObject::Connection> m_connectionList;
};
}  // namespace output


#endif  // SCANTAILOR_OTSUBINARIZATIONOPTIONSWIDGET_H
