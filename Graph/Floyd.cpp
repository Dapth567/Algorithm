#include <iostream>
#include <vector>

using namespace std;

// กำหนดค่า INF (Infinity) ให้สูงมากพอ แต่ไม่ใช้ INT_MAX เพื่อป้องกัน Error จากการบวกค่าเพิ่ม (Overflow)
const int INF = 1e9;

/**
 * ฟังก์ชัน Floyd-Warshall สำหรับหาเส้นทางสั้นที่สุดระหว่างทุกคู่จุด (All-pairs shortest path)
 * @param graph: เมทริกซ์ประชิด (Adjacency Matrix) ที่เก็บค่าน้ำหนักของเส้นเชื่อม
 * @param V: จำนวนจุดยอด (Vertices) ในกราฟ
 */
void floydWarshall(vector<vector<int>>& graph, int V) {
    // สร้างเมทริกซ์ dist[][] เพื่อเก็บระยะทางที่สั้นที่สุด 
    // เริ่มต้นให้มีค่าเหมือนกับเมทริกซ์ graph ที่รับเข้ามา
    vector<vector<int>> dist = graph;

    /* หัวใจของอัลกอริทึม: 
       เราจะลองนำจุด 'k' มาเป็น "จุดเชื่อมกลาง" ระหว่างจุด 'i' และ 'j' 
       แล้วดูว่าการเดินผ่านจุด k นั้นสั้นกว่าการเดินตรงๆ จาก i ไป j หรือไม่
    */
    for (int k = 0; k < V; k++) { // k คือจุดเชื่อมกลาง (Intermediate Vertex)
        for (int i = 0; i < V; i++) { // i คือจุดเริ่มต้น (Source Vertex)
            for (int j = 0; j < V; j++) { // j คือจุดปลายทาง (Destination Vertex)
                
                // ตรวจสอบว่ามีทางเดินจาก i ไป k และจาก k ไป j หรือไม่ (ต้องไม่ใช่ INF)
                // และตรวจสอบว่าระยะทาง (i -> k -> j) สั้นกว่าระยะเดิม (i -> j) หรือไม่
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    // หากสั้นกว่า ให้ปรับปรุงค่าระยะทางที่สั้นที่สุดใหม่
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // แสดงผลลัพธ์เมทริกซ์ระยะทางสั้นที่สุด
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // สมมติกราฟมี 4 จุดยอด
    int V = 4;
    
    // กำหนดเมทริกซ์ประชิดของกราฟ
    // 0 หมายถึงจุดตัวเอง, INF หมายถึงไม่มีเส้นเชื่อมโดยตรง
    vector<vector<int>> graph = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // เรียกใช้งานอัลกอริทึม
    floydWarshall(graph, V);

    return 0;
}