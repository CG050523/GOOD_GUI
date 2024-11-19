#ifndef HELLO_H
#define HELLO_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>
#include <string>

#include "common/common.h"
#include "common/cstring.h"
#include "common/gtime.h"
#include "common/logger.h"
#include "common/types.h"
#include "core/config.h"
#include "core/ftps.h"

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

QT_BEGIN_NAMESPACE
namespace Ui {
    class hello;
}
QT_END_NAMESPACE

class hello : public QDialog {
    Q_OBJECT

  public:
    hello(QWidget* parent = nullptr);
    ~hello();
    std::string get_Location() { return Location; }
    bool Start_Download(const std::string& Loc);
    ftpopt_t fpop;
    prcopt_t prop;
  private slots:
    void on_pushButton_clicked();

    void on_config_download_clicked();

    void on_main_dir_check_clicked();

    void on_time_modal_setting_activated(const QString& arg1);

    void on_minus_add_day_setting_activated(int index);

    void on_merge_sp3_setting_activated(int index);

    void on_print_wget_log_setting_activated(int index);

    void on_ftp_download_setting_activated(int index);

    void on_ftp_download_site_setting_activated(const QString& arg1);

    void on_obs_download_setting_activated(int index);

    void on_obs_type_setting_activated(const QString& arg1);

    void on_obs_pro_site_setting_activated(const QString& arg1);

    void on_obs_site_setting_activated(int index);

    void on_obs_name_length_setting_activated(int index);

    void on_nav_download_setting_activated(int index);

    void on_nav_type_setting_activated(const QString& arg1);

    void on_nav_site_choose_button_clicked();

    void on_nav_name_length_setting_activated(int index);

    void on_orb_clk_download_setting_activated(int index);

    void on_orb_clk_pro_site_setting_activated(int index);

    void on_orb_clk_clear_clicked();

    void on_orb_clk_name_length_setting_activated(int index);

    void on_erp_eop_download_setting_activated(int index);

    void on_erp_eop_pro_site_setting_activated(int index);

    void on_erp_eop_name_length_setting_activated(int index);

    void on_obx_download_setting_activated(int index);

    void on_obx_pro_site_setting_activated(int index);

    void on_ion_pro_site_setting_activated(int index);

    void on_ion_clear_clicked();

    void on_ion_name_length_setting_activated(int index);

    void on_trop_pro_site_setting_activated(const QString& arg1);

    void on_trop_site_choose_button_clicked();

    void on_trop_name_length_setting_activated(int index);

    void on_atx_download_setting_activated(int index);

    void on_GUI_download_clicked();

    void on_dsb_download_setting_activated(int index);

    void on_dsb_pro_site_setting_activated(int index);

    void on_osb_download_setting_activated(int index);

    void on_osb_pro_site_setting_activated(int index);

    void on_snx_download_setting_activated(int index);

    void on_snx_name_length_setting_activated(int index);

    void on_ion_download_setting_activated(int index);

    void on_roti_download_setting_activated(int index);

    void on_trop_download_setting_activated(int index);

    void on_nav_system_setting_activated(const QString& arg1);

    void on_nav_pro_site_setting_activated(const QString& arg1);

    void on_choose_thirdparty_dir_clicked();

  private:
    QStringList check_list;
    QStringList name_length_list;
    QStringList ftp_site_list;
    QStringList obs_type_list;
    QStringList obs_process_site_list;
    QStringList nav_system_list;
    QStringList nav_process_site_list;
    QStringList orb_clk_process_site_list;
    int orb_clk_add_count = 0;
    QStringList erp_eop_process_site_list;
    int ion_add_count = 0;

    std::string Location;
    std::string location_main_dir;
    int time_modal = 1;
    void set_dir();
    void init_exist_list();

  private:
    Ui::hello* ui;
};
#endif  // HELLO_H
