// 初始化参数
void init_ocxo_control() {
    // 控制电压范围
    set_voltage_range(0.0, 5.0);           // 0-5V
    
    // PID 参数
    set_pid_gains(0.1, 0.01, 0.001);       // Kp, Ki, Kd
    
    // 频率检测参数
    set_frequency_threshold(0.1);          // 0.1 ppb
    set_averaging_time(10);                // 10秒平均
    
    // 相位锁定参数
    set_phase_lock_threshold(50);          // ±50ns
    set_lock_timeout(1800);                // 30分钟锁定时间
    
    // 老化补偿
    set_aging_compensation(3.2, 0.3);      // +3.2ppb/天，30%不确定度
    
    // 保持模式
    set_holdover_limit(86400, 100, 10000); // 24小时，100ppb，10μs
}
