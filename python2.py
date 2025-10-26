import subprocess
import re
import time
def get_ip_addresses():
    """获取本机的IPv4和IPv6地址（兼容Python 3.6，解决编码问题）"""
    try:
        # 使用Popen处理编码问题
        process = subprocess.Popen(['ipconfig', '/all'], 
                                 stdout=subprocess.PIPE, 
                                 stderr=subprocess.PIPE,
                                 universal_newlines=False)  # 禁用自动解码
        
        output, _ = process.communicate()
        # 尝试UTF-8解码，失败则使用GBK解码并忽略错误
        try:
            output = output.decode('utf-8')
        except UnicodeDecodeError:
            output = output.decode('gbk', errors='ignore')
        
        ipv4_pattern = r'IPv4 地址[\. ]+: ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)'
        ipv6_pattern = r'IPv6 地址[\. ]+: ([a-f0-9:]+)'
        
        ipv4_addresses = re.findall(ipv4_pattern, output)
        ipv6_addresses = re.findall(ipv6_pattern, output)
        
        return {
            'IPv4': list(set(ipv4_addresses)) if ipv4_addresses else ["未找到IPv4地址"],
            'IPv6': list(set(ipv6_addresses)) if ipv6_addresses else ["未找到IPv6地址"]
        }
    
    except Exception as e:
        return {
            'IPv4': [f"获取IPv4地址出错: {str(e)}"],
            'IPv6': [f"获取IPv6地址出错: {str(e)}"]
        }

def get_wifi_password():
    """获取当前连接的WiFi名称和密码（兼容Python 3.6，解决编码问题）"""
    try:
        # 获取当前连接的WiFi名称
        process = subprocess.Popen(['netsh', 'wlan', 'show', 'interfaces'], 
                                 stdout=subprocess.PIPE, 
                                 stderr=subprocess.PIPE,
                                 universal_newlines=False)
        output, _ = process.communicate()
        
        try:
            output = output.decode('utf-8')
        except UnicodeDecodeError:
            output = output.decode('gbk', errors='ignore')
        
        ssid_match = re.search(r'SSID\s+: (.+)', output)
        
        if not ssid_match:
            return {"error": "未连接到WiFi"}
        
        ssid = ssid_match.group(1).strip()
        
        # 获取该WiFi的配置文件（包含密码）
        process = subprocess.Popen(['netsh', 'wlan', 'show', 'profile', f'name={ssid}', 'key=clear'], 
                                 stdout=subprocess.PIPE, 
                                 stderr=subprocess.PIPE,
                                 universal_newlines=False)
        output, _ = process.communicate()
        
        try:
            output = output.decode('utf-8')
        except UnicodeDecodeError:
            output = output.decode('gbk', errors='ignore')
        
        password_match = re.search(r'关键内容\s+: (.+)', output)
        password = password_match.group(1).strip() if password_match else "未找到密码"
        
        return {
            'SSID': ssid,
            'Password': password
        }
    
    except Exception as e:
        return {"error": str(e)}

def get_network_info():
    """获取所有网络信息"""
    print("正在获取网络信息...\n")
    
    # 获取IP地址
    print("=== IP地址信息 ===")
    ip_info = get_ip_addresses()
    print("IPv4 地址:", ', '.join(ip_info['IPv4']))
    print("IPv6 地址:", ', '.join(ip_info['IPv6']))
    
    # 获取WiFi信息
    print("\n=== WiFi信息 ===")
    wifi_info = get_wifi_password()
    if 'error' in wifi_info:
        print("错误:", wifi_info['error'])
    else:
        print("WiFi名称:", wifi_info['SSID'])
        print("WiFi密码:", wifi_info['Password'])

# 执行
if __name__ == "__main__":
    get_network_info()
